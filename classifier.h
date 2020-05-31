#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;
/**在classifier.cpp中的GNB类中实现train(self, data, labels) 方法。
训练高斯朴素贝叶斯分类器包括计算和存储每个标签/功能对数据的均值和标准差。
例如，给定标签“左转车道”和s导数​功能的，有必要计算和存储s导数的平均值和
标准偏差的带有``左更改车道''标签的所有数据点。*
*/
class GNB {
public:
    
	vector<string> possible_labels = {"left","keep","right"};

    vector<double>  left_means;
    vector<double>  left_stddev;
    
    vector<double>  keep_means;
    vector<double>  keep_stddev;
    
    vector<double>  right_means;
    vector<double>  right_stddev;
    
    vector<vector<double>>  feature_data_left;
    vector<vector<double>>  feature_data_keep;
    vector<vector<double>>  feature_data_right;

	/**
  	* Constructor
  	*/
 	GNB();

	/**
 	* Destructor
 	*/
 	virtual ~GNB();

 	void train(vector<vector<double> > data, vector<string>  labels);

  	string predict(vector<double>);

};

#endif



