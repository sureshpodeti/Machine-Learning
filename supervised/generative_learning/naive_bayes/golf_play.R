# Load the data into data frame
df <- read.csv('/home/podeti/Desktop/AI/Machine-Learning/Data/golf_play.csv')
n <- ncol(df)

# convert dataframe into matrix
data <- data.matrix(df)

# split the data into train and test data
library(caret)
partitionIndex <- createDataPartition(data[, n], p=0.7, list=FALSE)

data_train <- data[partitionIndex, ]
data_test <- data[-partitionIndex, ]

data_train_y_0 <- data_train[data_train[, n] == 0, ]
data_train_y_1 <- data_train[data_train[,n] == 1, ]

data_train_features_y_0 <- data_train_y_0[, -n]
data_train_target_y_0 <- data_train_y_0[, n]

data_train_features_y_1 <- data_train_y_1[, -n]
data_train_target_y_1 <- data_train_y_1[, n]

