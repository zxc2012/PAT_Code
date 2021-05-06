from urllib.parse import urlparse
from focal_loss.focal_loss import FocalLoss
from torchvision import models
from sklearn.metrics import confusion_matrix, classification_report, accuracy_score,precision_recall_fscore_support

# classification_report()
model=models.DenseNet()
url = 'http://localhost:8891/image/252/253/20210414102021_CP_1072_3115_0040.png'
parsed = urlparse(url)
par=parsed.path.replace("/image","C:/Users/78669/data/image")
FocalLoss(alpha=2, gamma=5)
print(par)
