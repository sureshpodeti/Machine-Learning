# load the dataset 
x <- read.table('/home/podeti/Desktop/AI/Machine-Learning/Data/ex3Data/ex3x.dat',header=FALSE)
y <- read.table('/home/podeti/Desktop/AI/Machine-Learning/Data/ex3Data/ex3y.dat',header=FALSE)

x <- data.matrix(x)
y <- data.matrix(y)

# data preprocessing 
x <- scale(x)

# split the data into train and test data
library(caret)
partitionIndex <- createDataPartition(y, p=0.7, list=FALSE)
x_train <- x[partitionIndex, ]
x_test <- x[-partitionIndex, ]

y_train <- data.matrix(y[partitionIndex, ])
y_test <- data.matrix(y[-partitionIndex, ])

# define cost function 
costFunction <- function(x,y, theta, m){
  return(sum(((x%*%theta)-y)^2)/(2*m))
}

# gradientdescent algorithm
gradientDescent <- function(x, y, theta, m, e=1e-5, alpha=0.01){
  while(TRUE){
    cost_prev <- costFunction(x, y, theta, m)
    # update theta
    theta <- theta - (alpha/m)*(t(x)%*%((x%*%theta) - y))
    cost_curr <- costFunction(x, y, theta, m)
    if(abs(cost_prev - cost_curr)<e){
      break
    }
  }
  return(theta)
}


m_train <- dim(x_train)[1]
n <- dim(x_train)[2]

ones <- rep(1, m_train)
x_train_ones <- cbind(ones, x_train)


# initialize theta
theta <- matrix(rep(0, n+1))

# define error tolerance
e <- 1e-30

# define learning rate
alpha <- 0.0001
thetaSol <-gradientDescent(x_train_ones, y_train, theta, m_train, e, alpha)

m_test <- dim(x_test)[1]
ones <- rep(1, m_test)
x_test_ones <- cbind(ones, x_test)
y_test_pred <- x_test_ones%*%thetaSol

par(mfrow=c(1,1))
plot(y_test_pred ~y_test, col='blue')
abline(a=1, b=1, col="red" )
