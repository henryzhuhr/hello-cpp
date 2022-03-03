// #include <iostream>
#include <functional>




// =========================================
// =========================================
// =========================================

// https://cppsenioreas.wordpress.com/2021/01/03/design-patterns-decorators-cpp/


// https://blog.csdn.net/qq_43605388/article/details/119962335?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1.pc_relevant_antiscan&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1.pc_relevant_antiscan&utm_relevant_index=2
/*!
 * @brief 装饰器基类
 * @tparam FUN_RET_TYPE 函数返回值类型
 * @tparam FUN_ARGS 函数参数类型
 */
template<typename FUN_RET_TYPE, typename ... FUN_ARGS>
class Decorator {
protected:
	//被装饰的函数
	std::function<FUN_RET_TYPE(FUN_ARGS...)> decorated_func;
public:
	explicit Decorator(const std::function<FUN_RET_TYPE(FUN_ARGS...)> &p_func) {
		decorated_func = p_func;
	}

	explicit Decorator(FUN_RET_TYPE(*p_func)(FUN_ARGS...)) :
			Decorator(std::function<FUN_RET_TYPE(FUN_ARGS...)>(p_func)) {
	}

	/*!
	 * 在这里实现装饰器的基本功能
	 * @param args
	 * @return
	 */
	virtual FUN_RET_TYPE operator()(FUN_ARGS...args) = 0;
};



/*!
 * 计时器
 * @tparam FUN_RET_TYPE
 * @tparam FUN_ARGS
 */
template<typename FUN_RET_TYPE, typename ... FUN_ARGS>
class FuncTimer : public Decorator<FUN_RET_TYPE, FUN_ARGS...> {
private:
	//计时器的提示字符串
	std::string tip_str;
public:
	explicit FuncTimer(const std::function<FUN_RET_TYPE(FUN_ARGS...)> &p_func, std::string tip_str = "")
			: Decorator<FUN_RET_TYPE, FUN_ARGS...>(p_func), tip_str(std::move(tip_str)) {
	}

	explicit FuncTimer(FUN_RET_TYPE(*p_func)(FUN_ARGS...), std::string tip_str = "")
			: Decorator<FUN_RET_TYPE, FUN_ARGS...>(p_func), tip_str(std::move(tip_str)) {
	}

	FUN_RET_TYPE operator()(FUN_ARGS...args) override {
		//使用函数前记录时间
		auto before = std::chrono::system_clock::now().time_since_epoch().count();
		//调用函数
		FUN_RET_TYPE result = this->decorated_func(args...);
		//调用函数后记录时间
		auto after = std::chrono::system_clock::now().time_since_epoch().count();
		//计算时间差并打印
		std::cout << tip_str << after - before << std::endl;
		return result;
	}
};



