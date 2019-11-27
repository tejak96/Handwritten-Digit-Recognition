REFERENCE URL : https://archive.ics.uci.edu/ml/datasets/Optical+Recognition+of+Handwritten+Digits

Two versions of this database available.

1) Preprocessed data can be found in optdigits.tra and optdigits.tes
   See optdigits.names for information regarding the preprocessing.

2) The original format of the data can be found in files prefixed with
   optdigits-orig.

Dataset has two files:
Training and Validation

Training Data Set:
	It has numbers information (32x32 characters) along with its result in the next line (Supervised learning)
	starting from 0..9 and has a repetitive pattern while varying
	aspects of each number over each pattern.
	Each number has upto 180 different models to train on.

Validation Data Set:
	It has a random and more noisy data that barely manages to resemble the number pattern
	Different algorithms can be used to deal with probability distributions and predict the
	outcome of the file which can be verified immediately with the result 
	provided in the next line to get accuracy.