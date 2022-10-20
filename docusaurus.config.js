// @ts-check
// Note: type annotations allow type checking and IDEs autocompletion

const lightCodeTheme = require('prism-react-renderer/themes/github');
const darkCodeTheme = require('prism-react-renderer/themes/dracula');

/** @type {import('@docusaurus/types').Config} */
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
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          sidebarPath: require.resolve('./sidebars.js'),
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.
          editUrl:
            'https://github.com/zxc2012/zxc2012.github.io/tree/master',
        },
        theme: {
          customCss: require.resolve('./src/css/custom.css'),
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      navbar: {
        title: 'Chance',
        logo: {
          alt: 'My Site Logo',
          src: 'img/logo.svg',
        },
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
      },
    }),
};

module.exports = config;
