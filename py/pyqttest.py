from matplotlib import pyplot as plt
import seaborn as sns

flights =  sns.load_dataset("flights")
fp = flights.pivot_table(index='month',columns='year',values='passengers')
sns.clustermap(fp,cmap='coolwarm')
plt.show()