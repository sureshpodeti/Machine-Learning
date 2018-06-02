# Load the data

df.age <- read.csv('/home/podeti/Desktop/AI/Machine-Learning/Data/ex2Data/ex2x.dat', header=FALSE)
df.height <- read.csv('/home/podeti/Desktop/AI/Machine-Learning/Data/ex2Data/ex2y.dat', header=FALSE)


# data preprocessing

library('caret')	
partionIndex <- createDataPartition(df.height$V1, p=0.7, list=FALSE)


x_train <- df.age[partionIndex, ]
x_test <- df.age[-partionIndex, ]

y_train <- df.height[partionIndex, ]
y_test <- df.height[-partionIndex,]


# cost function
cost_function <- function(x, y,theta, m){
   return (sum(((x%*%theta)-y)^2)/(2*m))
}

# gradient descent algorithm
gradient_descent <- function(x, y, theta, m, e=1e-5, alpha=0.01){

     while(TRUE){
	cost_prev <- cost_function(x, y,theta, m)
	# updating the thetas
	theta <- theta - (alpha /m)*(t(x)%*%((x%*%theta) - y))
	cost_curr <- cost_function(x, y, theta, m)
	if(abs(cost_prev - cost_curr)<e){
	  break;
	}
     }
     return(theta)
}



# append 1's 
m <- length(x_train)
n <- 2
ones <- rep(1, m)
x_train_ones <- matrix(data=c(ones, x_train), nrow=m, byrow=FALSE)


# initialize theta
theta <- matrix(data = rep(0, 2), nrow=n, byrow=FALSE)

# define error tolerance
e <- 1e-10

# define learning rate
alpha <- 0.01

y_train <- matrix(data=c(y_train), nrow=length(y_train), byrow=FALSE)


theta <- gradient_descent(x_train_ones, y_train, theta, m, e, alpha)



# results  visualization 
par(mfrow=c(1,1))
m_test <- length(x_test)

ones <- rep(1,m_test)
x_test_ones <- matrix(data=c(ones, x_test), nrow=m_test, byrow=FALSE)
y_test_pred <- x_test_ones%*%theta

plot(y_test ~x_test, col='blue')
abline(a=theta[1], b=theta[2], col="red")

