import React from 'react';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import Layout from '@theme/Layout';

import styles from './index.module.css';

export default function Home() {
  const {siteConfig} = useDocusaurusContext();
  return (
    <Layout
      title={`Hello from ${siteConfig.title}`}
      description="Description will go into a meta tag in <head />">
      <div  className={styles.hero_wrap} style={{
        background: `url(./img/bg.svg) center center/cover no-repeat`
      }}>
        <p className={styles.hero_subtitle}>{siteConfig.tagline}</p>
      </div>
    </Layout>
  );
}
