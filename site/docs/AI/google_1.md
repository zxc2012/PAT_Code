# Google机器学习入门--Pandas 简介

## Pandas 简介
学习目标：

- 大致了解 pandas 库的 DataFrame 和 Series 数据结构
- 存取和处理 DataFrame 和 Series 中的数据
- 将 CSV 数据导入 pandas 库的 DataFrame
- 对 DataFrame 重建索引来随机打乱数据
----
pandas 中的主要数据结构被实现为以下两类：

`DataFrame`，您可以将它想象成一个关系型数据表格，其中包含多个行和已命名的列。
`Series`，它是单一列。DataFrame 中包含一个或多个 Series，每个 Series 均有一个名称。
数据框架是用于数据操控的一种常用抽象实现形式。Spark 和 R 中也有类似的实现。

----
创建 Series 的一种方法是构建 Series 对象。例如：
```py
pd.Series(['San Francisco', 'San Jose', 'Sacramento'])
```
您可以将映射 string 列名称的 dict 传递到它们各自的 Series，从而创建DataFrame对象。如果 Series 在长度上不一致，系统会用特殊的 NA/NaN 值填充缺失的值。例如：
```py
city_names = pd.Series(['San Francisco', 'San Jose', 'Sacramento'])
population = pd.Series([852469, 1015785, 485199])
cities = pd.DataFrame({ 'City name': city_names, 'Population': population })
```
---
DataFrames 的修改方式也非常简单。例如，以下代码向现有 DataFrame 添加了两个 Series：
```py
cities['Area square miles'] = pd.Series([46.87, 176.53, 97.92])
cities['Population density'] = cities['Population'] / cities['Area square miles']
cities
```
index|City name	|Population	|Area square miles	|Population density
----|-------- | -------- |-------- |-------- 
0 | 	San Francisco | 	852469	 | 46.87 | 	18187 | .945381
1 |	San Jose	 |1015785 |	176.53	 |5754.177760
2	 |Sacramento	 |485199	 |97.92	 |4955.055147