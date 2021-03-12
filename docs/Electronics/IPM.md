# 逆透视变换车道线检测

## 摘要
随着社会的进步和发展，安全驾驶和汽车的简便操作越来越受到人们的重视。苹果、谷歌和特斯拉等公司相继推出了无人驾驶系统，国内的厂商也对此领域产生了高度兴趣。基于人工智能和大数据的无人驾驶技术，被认为是消除交通安全问题的最终方法。从美国DARPA 挑战赛到中国未来智能车大赛，无人驾驶技术在全世界兴起了一阵热潮。
对于无人驾驶系统来说，车道线检测是非常重要的技术。到现在为止，已经有一些基于机器视觉的无人驾驶技术得到了应用。对于车道线的检测方法大致可以归结为三种思想：基于车道线模型的方法和基于车道线特征的方法。基于车道线模型的算法就是针对结构化道路，根据其道路形状对车道线进行建模，可以有效的克服路面脏污、光照强、阴影等环境因素造成的影响。基于车道线特征的算法主要是两点：特征提取和特征聚合。首先根据目标信息，选取合适的特征，然后利用这些特征对像像素点进行归类处理，根据一定的准则将车道线类像素提取出来，进行聚合处理。
其中，一部分算法直接检测道路的边缘，而另一些算法首先利用道路的部分参数(例如颜色信息)来确定道路边缘。算法应用的技术也有很大差别(霍夫变换、逆透视变换和神经网络等)。其中，逆透视变换(IPM)技术己经在一些实验中得到了实际验证，如意大利帕尔玛大学的GOLD就使用了技术，对图像进行预处理；还有Massimo Bertozzi等使用双目立体视觉的进行障碍物检测，都取得了很好的效果。
本文提出了一种基于逆透视变换的车道线检测算法，首先通过matlab编写图像处理程序，然后将其在嵌入式智能小车上验证，将MT9V032摄像头拍摄的图像转换为俯视图，接着采用边缘检测的方法对车道标识线进行了提取，提取中线效果很好。
## 逆透视变换
车载摄像机拍摄到的场景图像是三维空间的场景在二维空间的投影,在对道路情况进行识别的过程中,需要一种逆的求解过程,即从已经得到的二维图像还原成俯视的路面图像.此即逆透视变换。

由小孔成像原理可知，摄像机三维世界坐标(X,Y,Z)到二维图像坐标(x,y)变换的关系 为


![在这里插入图片描述](https://img-blog.csdnimg.cn/2020052121534723.png)(1.1)
根据式1.1，可由三维世界坐标得到二维图像坐标，由于Z未知，所以反之不能实现，考虑到智能车在一般平面道路上行驶，可令Z = 0，则1.1式可变换为
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521215543375.png)(1.2)
式1.2可以建立二维像素坐标与三维世界平面坐标的映射关系，通过矩阵变换得
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521215623749.png)(1.3)
其中 
>![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521215700405.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521215733564.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521215818488.png)
 
 由此得
 >![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521215920713.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521215906636.png)
 
 整理成矩阵形式
 >![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521215959748.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521220046771.png)(1.4)
 
 设
 >![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521220219405.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521220242360.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521220303985.png)

则式1.4用矩阵可表示为
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200521220441818.png)
若要保证1.4有唯一解，则需满足增广矩阵为满秩，即rank(A|B)=8 ，那么就需要四组不相关的图像坐标系的点。
具体实现上，只需找出四组互不相关图像像素坐标和对应的世界坐标，然后通过matlab即可解出H参数矩阵，公式形式简单，便于大量图像数据处理。
对灰度图逆透视变换结果:
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020052122054291.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM5MzgwMjMw,size_16,color_FFFFFF,t_70)
## Code
我使用的C代码就不贴了，要看具体赛道情况，这里贴一个容易理解的Demo
```c
/*   文件：图像逆透视变换
 *
 *   说明：①图像采集前对桶形变换和逆透视变换初始化，建立相应映射表
 *         ②采集完一场图像后，若调用IPMCorrect（）函数， CorrImg[120][160]存储逆透视变换后图像
 *           若调用BuketCorrect（）函数，CorrImg[120][160]存储桶形后图像
 *         ③所有初始化函数均放在程序初始部分执行!!!
 *
 *   方案：①搜线：先对原始图像搜线，然后根据已知边界初步确定中线，对于单边丢线情况对图像局部逆透视变换，
 *                得到正视图，然后搜线获得中线，再通过逆映射表得到原始图像中线
 *                最后利用最小二乘法对中线均匀化，便于处理。
 *         ②测距：已知图像坐标，根据图像坐标与实际坐标的关系，可算出相应世界坐标与车距离（原点为摄像头中心）
 *
 *            世界坐标(X,Y)与图像坐标(u,v)关系如下
 *            u = (0.0128*X-0.0007*Y-0.0463)/(0.0037*Y+1)/0.0365+80;
 *            v = (-0.007*Y+4.1192)/(0.0037*Y+1)/0.0365+60;
 * 
 *            X = (1.24*u-0.021*v-100)/(0.0028*v+0.017); 
 *            Y = (3.65*v-63.092)/(0.1103-0.0135*v);
 *
 *   注：*******************************************************************************************
 */
   
#include "common.h" //山外common.h头文件
#include "IPM.h"

const double f = 0.0021;
const double dx = 0.0365,dy = 0.0365;

Site_t PMCorr[120][160];   //透视映射表，由原始图得到正视图
Site_t BuketCorr[120][160];  //桶形矫正映射表
Site_t IPMCorr[120][160];  //逆透视反矫正映射表，由正视图得到原始图

unsigned char CorrImg[120][160]; //矫正后图像数组，用于图像处理
                                  //桶形矫正和透视变换用的同一个数组


// 桶形矫正初始化，建立矫正表 
// k1 = -0.00001374; k2 = -0.00001057;  
     
void BuketCorrInit( float k1, float k2 ) //K1为X方向畸变参数，K2为Y方向畸变参数
{  
    uint8 imgWidth = 160;   // 获得摄像头图像尺寸  
    uint8 imgHeight = 120;  
  
    uint8 imgWd2 = imgWidth>>1;  
    uint8 imgHd2 = imgHeight>>1;  
  
    int it;  
    int jt;  
    int it2;  
    int jt2;  
  
    for( int i=0; i<imgHeight; i++ )  
    {  
        it = ( i + 1 ) - imgHd2; //  (i+1) 是其真正的图像坐标  
        for( int j=0; j<imgWidth; j++ )  
        {  
            float temp;  
  
            jt = ( j + 1 ) - imgWd2; // (j+1) 是其真正的图像坐标  
            temp = 1 + k1*it*it + k2*jt*jt; 
			
            it2 = (int)(temp * it);
            jt2 = (int)(temp * jt);  
  
            it2 = it2 + imgHd2 + 1;//注意数组越界
            jt2 = jt2 + imgWd2 + 1;  

            BuketCorr[i][j].x = jt2;  
            BuketCorr[i][j].y = it2;  
        }  
    }  
} 
  
void PMCorrInit(void)  //透视正变换初始化，建立正映射表
{
   int u,v;
   int x1,y1,i,j;
   double X,Y,m,n,a,b;
   unsigned char value; 
   
   
   for(v=0;v<120;v++)    //矫正后图像坐标(u,v)
   {
     for(u=0;u<160;u++)
     {
       
          X=(u-80)*dx/f; // 映射到世界坐标(X,Y)
          Y =(130-v)*dy/f;
        
          n = (0.0128*X-0.0007*Y-0.0463)/(0.0037*Y+1)/0.0365+80;
          m = (-0.007*Y+4.1192)/(0.0037*Y+1)/0.0365+60;  //映射到原始图像坐标(n,m)
          
          j = floor(n);   //floor() iar系统库函数
          i = floor(m);  //利用临界插值
          a = m-i;
          b = n-j;
          if(a<0.5)
          {
            y1 = i;
          }
          else
          {y1 = i+1;}
          
          if(b<0.5)
          {x1 = j;}
          else
          {x1 = j+1;}
          
          if(x1>=0&&x1<160&&y1>=0&&y1<120)
          {
            PMCorr[v][u].x = x1; //映射到数组
            PMCorr[v][u].y = y1;
          }        
     }
     
   }
}

void IPMCorrInit(void) //逆透视映射初始化，建立反矫正表
{
   int u,v;
   int i,j,it,jt;
   double X,Y,m,n,a,b;
 
   for(v=0;v<120;v++) //%原始图像坐标(u,v)
    {
         for(u=0;u<160;u++)
         {
              X = (1.24*u-0.021*v-100)/(0.0028*v+0.017);//原始图像映射到世界坐标
              Y = (3.65*v-63.092)/(0.1103-0.0135*v); 
             
              n = X*f/dx+80;
              m = 130-Y*f/dy; //%映射到矫正图像坐标(n,m)
              
              j = floor(n);i = floor(m);  //%利用双线性插值法或者临近插值
              a = m-i;b = n-j;
            
             if(a<0.5)
               it = i;
             else
               it = i+1;
             
             if(b<0.5)
               jt = j;
             else
               jt = j+1;
             
             if(it>0&&it<120&&jt>0&&jt<160)
             {
               IPMCorr[v][u].x = jt;
               IPMCorr[v][u].y = it;
             }

         }     
    }  
}

// 镜头径向畸变校正  
void BuketCorrect(unsigned char (*ImgOrigin)[160])  
{  
    int it;  
    int jt;  
  
    for( int i=0; i<120; i++ )  
    {  
        for( int j=0; j<160; j++ )  
        {  
            it = BuketCorr[i][j].y;  
            jt = BuketCorr[i][j].x;  
            CorrImg[i][j] = ImgOrigin[it][jt];
        }  
    }  
}  


void PMCorrect(unsigned char (*ImgOrigin)[160] ) //透视正变换，用于矫正每场采集图像
{
    int it,jt,m,n;
    int ImgTemp[120][160];
    BuketCorrect(ImgOrigin); //先桶形映射
    for(m=0;m<120;m++)  //桶形变换后图像拷贝，用作逆透视映射
    {
       for(n=0;n<160;n++)
       {
           ImgTemp[m][n] = CorrImg[m][n];
       }
    }
    for( int i=0; i<120; i++ )  
    {  
        for( int j=0; j<160; j++ )  
        {  
            it = PMCorr[i][j].y;  
            jt = PMCorr[i][j].x;   
            CorrImg[i][j] = ImgTemp[it][jt];
        }  
    }  
}


```