# DCGAN-Gradient-Tape
A study of the use of the Tensorflow GradientTape class for differentiation and custom gradient generation along with its use to implement a Deep-Convolutional Generative Adversarial Network (GAN) to generate images of hand-written digits.

## Overview

* Here, we examine in detail the uasge of **GradientTape**, a custom differentiation class by Tensorflow which allows us to calculate the derivative of complex functions programmatically. This has immense applications in Deep Learning as we can build customer hidden layers in Neural Networks and specify how the gradients of the loss function are calculated during the training phase. </br>
([Source](https://www.tensorflow.org/api_docs/python/tf/GradientTape))

* We have also studied an implementation of a [Generative Adversarial Network](https://arxiv.org/abs/1406.2661) (**GAN**) to accept noise vector as an input to the Generator and output synthetically generated images of hand-written digits, similar to the ones on the [MNIST Dataset](http://yann.lecun.com/exdb/mnist/). We will be looking at a specific variation called Deep Convolutional Generative Adversarial Network (DCGAN) for this task. </br>
([Source](https://www.tensorflow.org/tutorials/generative/dcgan))

## Dataset 

We have used the renowned [MNIST Handwritten Digits Dataset](http://yann.lecun.com/exdb/mnist/) containing 60,000 train samples and 10,000 test samples of 28x28 grayscale images depicting numerical digits written by a huge number of human subjects. 

## References

* [Applications of GANs](https://medium.com/@jonathan_hui/gan-some-cool-applications-of-gans-4c9ecca35900)
* [GAN Tricks and Hacks](https://github.com/soumith/ganhacks)
* [MNIST GAN Code Example](https://medium.com/datadriveninvestor/generative-adversarial-network-gan-using-keras-ce1c05cfdfd3)
* [Stanford Course on Deep Generative Models](https://deepgenerativemodels.github.io/)
* [Keras Implementations of Various GAN architectures](https://github.com/eriklindernoren/Keras-GAN)
