## STL,基础数学
1.输入方式大总结
> getline(cin,str):  
std::basic_istream& getline(std::basic_istream&__is, std::__cxx11::basic_string& __str);
```cpp
//解析一个字符的三种方式
scanf("%c",&ch);
ch=cin.get();
ch=getchar();
//解析一个字符串的方式
char m[20];
gets(m);     
cin.getline(m,5);//多了一个参数，可以加结束符
cin.get(m,20);//多了一个参数，可以加结束符
```
>%2d就是将数字按照宽度为2 采用右对齐方式输出，若数据位数不到2位，则左边补空格

>%02d和%2d差不多 只不过左边补0

2."对应"的处理--

##### `法1:建表`
```cpp
char c[14] = {"0123456789ABC"};
printf("#");
for(int i = 0; i < 3; i++) {
    int num;
    scanf("%d", &num);
    printf("%c%c", c[num/13], c[num%13]);
}
return 0;
```
##### `法2:直接函数输出`

3.cmp的写法
```cpp
int cmp(node& a, node& b) {//Tips:引用传递和地址传递效率高于直接传递
	if ((a.de1 + a.cai) != (b.de + b.cai))        
        return (a.de + a.cai) > (b.de + b.cai);//技巧:以求和代替求平均值
	else if (a.de != b.de) return a.de > b.de;
	else return strcmp(a.name, b.name) < 0;//char name[9]
        //还可以string a.name<b.name;
}
```
> 并列排名问题
```cpp
struct node {
	int id, best;
	int score[4], rank[4];
};//一般一个结构体
for(i=0;i<sch.size();++i){
 for(j=0;j<k;++j){
        bool y;
        int choice=sch[i].sc[j];
        int x=ans[choice].size();
        if(x>0){
            int last=x-1;
            y=sch[i].grade[0]==ans[choice][last].grade[0]&&sch[i].grade[1]==ans[choice][last].grade[1];
            x=y?ans[choice][last].rank:x;
        }
        if(x<full[choice]||y){
            ans[sch[i].sc[j]].push_back(sch[i];
            break;
        }
}
for(flag = 0; flag <= 2; flag++) {
        sort(ans.begin(), ans.end(), cmp1);
        for(int i = 0; i < n; i++) {
            ans[i].rank[flag] = i;
            if(i>0&&ans[i].grade[flag] == ans[i-1].grade[flag])//注意多一个判断还有反向            
            ans[i].ans[flag] = ans[i-1].rank[flag];
        }
}
```
4.输出格式
```cpp
for (int i = 0; i < 4; i++) {
	sort(v[i].begin(), v[i].end(), cmp);
	for (int j = 0; j < v[i].size(); j++){
        if(j!=0)printf(" ");
		printf("%d", v[i][j].num);
    }
    printf("\n");
}
```
5.排序题

>多维排序-->找参考系

如比较时间实际可以比较他们分别从0:0:0开始的时间,存储的时候也可以只存储时间

**[易错点]多余链表、记录的问题**

PAT1016 Phone Bills
>夹逼题:[a,b]!c
```cpp
for(j=temp;st[j].time<=cal(c)&&j<st.size();++j)
    if(st[j].status==0)sum++;
    else sum--;
```
6.运行超时:
循环内套了一个大函数:如循环内sort(>1000)