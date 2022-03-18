const { path } = require('@vuepress/shared-utils')
import type { Plugin } from '@vuepress/core'


const copyPlugin = {
    name: 'copy-plugin',
    define:{
        'COPY_PLUGIN_PATH': path.resolve(__dirname, 'lib'),
    },
    clientAppRootComponentFiles: path.resolve(
        __dirname,
        '../client/components/BackToTop.js'
      ),
}
export default copyPlugin