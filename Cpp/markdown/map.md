## map,string
1.输入方式大总结
- getline(cin,str):
std::basic_istream& getline(std::basic_istream&__is, std::__cxx11::basic_string& __str);
- 总结
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
2.对应的处理--
法1:建表
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
法2:直接函数输出
3.cmp的写法
```cpp
int cmp(struct node a, struct node b) {
	if ((a.de1 + a.cai) != (b.de + b.cai))        
        return (a.de + a.cai) > (b.de + b.cai);
	else if (a.de != b.de)       
        return a.de > b.de;
	else       
        return a.num < b.num;
}
```
```cpp
struct node {
	int id, best;
	int score[4], rank[4];
};
for(flag = 0; flag <= 3; flag++) {
        sort(stu.begin(), stu.end(), cmp1);
        for(int i = 0; i < n; i++) {
                stu[i].rank[flag] = i;
                if(i>0&&stu[i].score[flag] == stu[i-1].score[flag])                
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
}
```
4.输出格式
```cpp
for (int i = 0; i < 4; i++) {
	sort(v[i].begin(), v[i].end(), cmp);
	for (int j = 0; j < v[i].size(); j++)
		printf("%d %d %d\n", v[i][j].num, v[i][j].de, v[i][j].cai);
}
```