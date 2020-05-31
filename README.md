# Self driving cars: implementing Naive Bayes to predict lane changes. 

In this exercise you will implement a Gaussian Naive Bayes classifier to predict the behavior of vehicles on a highway. In the image below you can see the behaviors you'll be looking for on a 3 lane highway (with lanes of 4 meter width). The dots represent the d (y axis) and s (x axis) coordinates of vehicles as they either...

    1. change lanes left (shown in blue)
    2. keep lane (shown in black)
    3. or change lanes right (shown in red)

![alt text](https://github.com/cacheop/gaussian_naive_bayes/blob/master/naive-bayes.png?raw=true")

Your job is to write a classifier that can predict which of these three maneuvers a vehicle is engaged in given a single coordinate (sampled from the trajectories shown below).

Each coordinate contains 4 features:

    - s
    - d
    - dot s
    - dot d 


You also know the lane width is 4 meters (this might be helpful in engineering additional features for your algorithm).

## Instructions

1. Implement the `train(self, data, labels)` method in the class `GNB` in `classifier.cpp`.

Training a Gaussian Naive Bayes classifier consists of computing and storing the mean and standard deviation from the data for each label/feature pair. For example, given the label "change lanes left” and the feature s˙\dot{s}s˙, it would be necessary to compute and store the mean and standard deviation of s˙\dot{s}s˙ over all data points with the "change lanes left” label.

Additionally, it will be convenient in this step to compute and store the prior probability p(C_k) for each label C_k. This can be done by keeping track of the number of times each label appears in the training data.

 2. Implement the predict(self, observation) method in classifier.cpp.

 Given a new data point, prediction requires two steps:
 1. Compute the conditional probabilities for each feature/label combination. For a feature `x` and label `C` with mean μ\muμ and standard deviation σ\sigmaσ (computed in training), the conditional probability can be computed using the formula here:

![alt text](https://github.com/cacheop/gaussian_naive_bayes/blob/master/p1.png?raw=true")

Here `v` is the value of feature xxx in the new data point.

2. Use the conditional probabilities in a Naive Bayes classifier. This can be done using the formula here:

![alt text](https://github.com/cacheop/gaussian_naive_bayes/blob/master/p2.png?raw=true")

In this formula, the argmax is taken over all possible labels CkC_kCk​ and the product is taken over all features `C(k)` with values `v(i)`.


NOTE: The raw value of the `d` coordinate may not be that useful. But `d % lane_width` might be helpful since it gives the relative position of a vehicle in it's lane regardless of which lane the vehicle is in.



