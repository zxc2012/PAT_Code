// @ts-check
// Note: type annotations allow type checking and IDEs autocompletion

const lightCodeTheme = require('prism-react-renderer/themes/github');
const darkCodeTheme = require('prism-react-renderer/themes/dracula');
const math = require('remark-math');
const katex = require('rehype-katex');

async function createConfig(){
  const mdxMermaid = await import("mdx-mermaid");
  const config = {
    title: 'My Site',
    tagline: 'Dinosaurs are cool',
    url: 'https://zxc2012.github.io',
    baseUrl: '/',
    onBrokenLinks: 'throw',
    onBrokenMarkdownLinks: 'warn',
    favicon: 'img/favicon.ico',
  
    // GitHub pages deployment config.
    // If you aren't using GitHub pages, you don't need these.
    organizationName: 'zxc2012', // Usually your GitHub org/user name.
    projectName: 'zxc2012.github.io', // Usually your repo name.
  
    presets: [
      [
        '@docusaurus/preset-classic',
        ({
          docs: {
            sidebarPath: require.resolve('./sidebars.js'),
            remarkPlugins: [math, mdxMermaid.default],
            rehypePlugins: [katex],
            editUrl:
              'https://github.com/zxc2012/zxc2012.github.io/tree/master',
          },
          theme: {
            customCss: require.resolve('./src/css/custom.css'),
          },
        }),
      ],
    ],
    stylesheets: [
      {
        href: 'https://cdn.jsdelivr.net/npm/katex@0.15.2/dist/katex.min.css',
        type: 'text/css',
        integrity:
          'sha384-MlJdn/WNKDGXveldHDdyRP1R4CTHr3FeuDNfhsLPYrq2t0UBkUdK2jyTnXPEK1NQ',
        crossorigin: 'anonymous',
      },
    ],
    themeConfig:
      /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
      ({
        navbar: {
          items: [
            {
              label: "🎓cs专业课",
              type: 'docSidebar',
              sidebarId: 'cs',
              position: 'left',
            },
            {
              label: "☕️C++&Java",
              type: 'docSidebar',
              sidebarId: 'C',
              position: 'left',
            },
            {
              label: "✏️算法总结",
              type: 'docSidebar',
              sidebarId: 'Algorithms',
              position: 'left',
            },
            {
              label: "✈️Overseas",
              type: 'docSidebar',
              sidebarId: 'Overseas',
              position: 'left',
            },
            {
              label: "🍌Leetcode & OJ",
              type: 'docSidebar',
              sidebarId: 'OJ',
              position: 'left',
            },
            {
              label: "💡Software Development",
              type: 'docSidebar',
              sidebarId: 'SDE',
              position: 'left',
            },
            {
              label: "🕹️Electronics",
              type: 'docSidebar',
              sidebarId: 'Electronics',
              position: 'left',
            },
            {
              label: "🍉机器学习",
              type: 'docSidebar',
              sidebarId: 'AI',
              position: 'left',
            },
          ],
        },
        prism: {
          theme: lightCodeTheme,
          darkTheme: darkCodeTheme,
          additionalLanguages: ['java','armasm','verilog'],
        },
        mermaid: {
          theme: {light: 'neutral', dark: 'forest'},
        },
      }),
  };
  return config;
}


module.exports = createConfig;
