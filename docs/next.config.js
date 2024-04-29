const withNextra = require('nextra')({
  theme: 'nextra-theme-docs',
  themeConfig: './theme.config.jsx'
});

module.exports = withNextra({
	basePath: '/hydra',
	assetPrefix: '/hydra/',

	output: 'export',
	images: {
		unoptimized: true,
	},
});
