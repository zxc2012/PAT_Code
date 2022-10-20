import React from 'react';
import clsx from 'clsx';
import Link from '@docusaurus/Link';
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
        <h1 className={styles.hero_title}>{siteConfig.title} 前端 开发 javaScript 个人记录 博客</h1>
        <p className={styles.hero_subtitle}>{siteConfig.tagline}</p>
        {/* <header>
          <div className={styles.container}>
            
            <p className="hero__subtitle">{siteConfig.tagline}</p>
            <div className={styles.buttons}></div>
          </div>
        </header> */}
      </div>
    </Layout>
  );
}
