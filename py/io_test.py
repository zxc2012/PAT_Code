from urllib.parse import urlparse
from focal_loss.focal_loss import FocalLoss
url = 'http://localhost:8891/image/252/253/20210414102021_CP_1072_3115_0040.png'
parsed = urlparse(url)
par=parsed.path.replace("/image","C:/Users/78669/data/image")
FocalLoss(alpha=2, gamma=5)
print(par)
