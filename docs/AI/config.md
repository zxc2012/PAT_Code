# GPU
---
## 显示所有可用于tensorflow的设备
```py
from tensorflow.python.client import device_lib
print(device_lib.list_local_devices())
```
### Sample output
[名称：“ / cpu：0” device_type：“ CPU” memory_limit：268435456位置{}化身：4402277519343584096，

名称：“ / gpu：0” device_type：“ GPU” memory_limit：6772842168本地化{bus_id：1}化身：7471795903849088328 physical_device_desc：“设备：0，名称：GeForce GTX 1070，pci总线ID：0000：05：00.0”]
## Run code
```py
CUDA_VISIBLE_DEVICES=0 python filename.py#Device number up
```
### Or *in python file*
```py
os.environ["CUDA_VISIBLE_DEVICES"] = "0" # or :export CUDA_VISIBLE_DEVICES=0
```
---
# 源配置
---
```py
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge 
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/r
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/pro
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/msys2/
conda config --set show_channel_urls yes
```