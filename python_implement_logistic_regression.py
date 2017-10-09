import numpy as np
import matplotlib.pyplot as plt
import h5py
import scipy
from PIL import Image
from scipy import ndimage
from lr_utils import load_dataset

# 定义sigmoid函数
def sigmoid(x):
    s = 1/(1+np.exp(-x))
    return s

# 初始化w和b两个参数
def initialize_with_zeros(dim):
    w = np.zeros([dim,1])
    b = 0.

    assert(w.shape==(dim,1))
    assert(isinstance(b,float) or isinstance(b,int))

    return w,b

# 计算正向传播和反向传播
def propagate(w,b,X,Y):
    m = X.shape[1]
    # 正向传播
    A = sigmoid(np.dot(w.T,X)+b)
    # 成本函数
    cost = -np.sum(Y*np.log(A)+(1-Y)*np.log(1-A),axis=1)/m

    # 反向传播
    dw = np.dot(X,(A-Y).T)/m
    db = np.sum(A-Y,axis=1)/m

    # 断言
    assert(dw.shape == w.shape)
    assert(db.dtype == float)
    cost = np.squeeze(cost)
    assert(cost.shape == ())

    grads = {"dw":dw,"db":db}
    return cost,grads

# 使用梯度下降法优化得到参数w和b
def optimize(w,b,X,Y,num_iterations,learning_rate,print_cost=False):
    costs = []
    for i in range(num_iterations):
        cost,grads = propagate(w,b,X,Y)
        dw = grads['dw']
        db = grads['db']

        w = w-learning_rate*dw
        b = b-learning_rate*db

        if(i%100 == 0):
            costs.append(cost)
            if(print_cost):
                print("cost after iteration %i:%f"%(i,cost))
    
    params = {'w':w,'b':b}
    grads = {'dw':dw,'db':db}

    return params,grads,costs

# 使用优化的到的参数进行预测
def predict(w,b,X):
    m = X.shape[1]
    Y_predictions = np.zeros([1,m])
    
    assert(w.shape[0] == X.shape[0])
    A = sigmoid(np.dot(w.T,X)+b)

    for i in range(A.shape[1]):
        Y_predictions[0,i] = 1 if A[0,i]>=0.5 else 0
    
    return Y_predictions

# 最终的神经网络模型
def model(X_train,Y_train,X_test,Y_test,num_iterations=2000,learning_rate=0.5,print_cost=False):
    w,b = initialize_with_zeros(X_train.shape[0])
    params,grads,costs = optimize(w,b,X_train,Y_train,num_iterations,learning_rate,print_cost)

    w = params['w']
    b = params['b']

    Y_prediction_test = predict(w,b,X_test)
    Y_prediction_train = predict(w,b,X_train)

    print("train accuracy:{} %".format(100-np.mean(np.abs(Y_prediction_train-Y_train))*100))
    print("test accuracy:{} %".format(100-np.mean(np.abs(Y_prediction_test-Y_test))*100))

    d = {"costs": costs,
        "Y_prediction_test": Y_prediction_test, 
        "Y_prediction_train" : Y_prediction_train, 
        "w" : w, 
        "b" : b,
        "learning_rate" : learning_rate,
        "num_iterations": num_iterations}

    return d

# sigmoid函数测试
print(sigmoid(np.array([0,2])))

# propagate函数测试
w,b,X,Y = np.array([[1],[2]]),2,np.array([[1,2],[3,4]]),np.array([[1,0]])
cost,grads = propagate(w,b,X,Y)
print(cost,grads)

# optimize函数测试
params, grads, costs = optimize(w, b, X, Y, num_iterations= 100, learning_rate = 0.009, print_cost = False)
print(params,grads,costs)

# predict函数测试
print ("test predictions = " + str(predict(w, b, X)))

# 加载数据集
train_set_x_orig,train_set_y,test_set_x_orig,test_set_y,classes=load_dataset()
print("train_set_x_orig.shape: ",train_set_x_orig.shape)
print("test_set_x_orig.shape: ",test_set_x_orig.shape)
num_px = train_set_x_orig.shape[1]

# 显示训练集的一张图片
index = 25
plt.figure()
plt.imshow(train_set_x_orig[index])
plt.show()

# 序列化X矩阵：(num_px*num_px*3)
train_set_x_flatten = train_set_x_orig.reshape(train_set_x_orig.shape[0],-1).T
test_set_x_flatten = test_set_x_orig.reshape(test_set_x_orig.shape[0],-1).T
print("train_set_x_flatten.shape: ",train_set_x_flatten.shape)
print("test_set_x_flatten.shape: ",test_set_x_flatten.shape)

# 归一化
train_set_x = train_set_x_flatten/255
test_set_x = test_set_x_flatten/255

# 最终结果
d = model(train_set_x, train_set_y, test_set_x, test_set_y, num_iterations = 2000, learning_rate = 0.005, print_cost = True)
# print(d)

# 显示原图和预测结果
index = 4
plt.imshow(test_set_x[:,index].reshape([num_px,num_px,3]))
print("real result = "+str(test_set_y[0,index])+"and your predict = "+str(d['Y_prediction_test'][0,index]))
plt.figure()
plt.plot(np.squeeze(d['costs']))
plt.ylabel('cost')
plt.xlabel('iterations(per hundreds)')
plt.title("learning rate = "+str(d['learning_rate']))
plt.show()

# 不同的学习率测试
learning_rates = [0.01, 0.001, 0.0001]
models = {}
for i in learning_rates:
    print ("learning rate is: " + str(i))
    models[str(i)] = model(train_set_x, train_set_y, test_set_x, test_set_y, num_iterations = 1500, learning_rate = i, print_cost = False)
    print ('\n' + "-------------------------------------------------------" + '\n')

for i in learning_rates:
    plt.plot(np.squeeze(models[str(i)]["costs"]), label= str(models[str(i)]["learning_rate"]))

plt.ylabel('cost')
plt.xlabel('iterations')

legend = plt.legend(loc='upper center', shadow=True)
frame = legend.get_frame()
frame.set_facecolor('0.90')
plt.show()
