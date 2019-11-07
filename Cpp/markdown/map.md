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