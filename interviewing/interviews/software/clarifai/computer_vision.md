# Abstract

- This document explores computer vision, its techniques, researches and uses.

## Computer Vision Overview

1. What is?
   1. An interdisciplinary scientific field that deals with how computers can be made to gain high-level understanding from digital images or videos. It seeks to automate tasks that the human visual system can do.
      1. Its tasks include methods for acquiring, processing, analyzing and understanding digital images, and extraction of high-dimensional data from the real world in order to produce numerical or symbolic information.
      2. Understanding digital images means the transformation of visual images into descriptions of the world that can interface with other though processes and elicit appropriate action.
      3. It can be seen as the **disentangling of symbolic information from image data using models constructed with the aid of geometry, physics, statistics and learning theory**.
   2. A scientific discipline concerned with the theory behind artificial systems that extract information from images. The image data can take many forms, such as video sequences, views from multiple cameras, or multi-dimensional data from a medical scanner. It seeks to apply its theories and models for the construction of computer vision systems.
      1. Sub-domains include **scene reconstruction, event detection, video tracking, object recognition, 3D pose estimation, learning, indexing, motion estimation, and image restoration**.
2. Application
   1. **Automatic inspection** (manufacturing applications)
   2. **Assisting humans in identification tasks**, e.g., a species identification system
   3. **Controlling processes**, e.g., an industrial robot.
   4. Detecting events (visual surveillance or people counting)
   5. Interaction (the input to a device for computer human interaction)
   6. Modeling objects or environments (medical image analysis or topographical modeling)
   7. Navigation (an autonomous vehicle or mobile robot)
   8. Organizing information (indexing database of images and image sequences)
3. Recognition
   1. Varieties in image recognition
      1. Object Recognition - **one or several pre specified or learned objects or object classes can be recognized,** usually together with their 2D positions in the image or 3D poses in the scene.
      2. Identification - an individual instance of an object is recognized. Ex includes identification of a specific person's face or fingerprint, identification of handwritten digits, or identification of a specific vehicle.
      3. Detection - **The image data are scanned for a specific condition** (Detection of abnormal cells or tissues). Detection based on relatively simple and fast computations is sometimes used for finding smaller regions of interesting image data which can be further analyzed by more computationally demanding techniques to produce a correct interpretation.
4. Tasks based on recognition
   1. Content-based image retrieval
      1. Finding all images in a larger set of images which have a specific content.
         1. Input can be an image or high level search criteria given as text input.
   2. Pose estimation
      1. Estimating the position or orientation of a specific object relative to the camera. It helps robot arm in retrieving objects from a conveyer belt in an assembly line
   3. Optical Character recognition (OCR)
      1. Identifying characters in images of printed handwritten text, usually with a view of encoding text in a format more amenable to editing or indexing.
   4. 2D code reading like QA code or data matrixes
   5. Facial recognition
   6. Shape Recognition Technology
5. Motion Analysis
   1. Several tasks relate to motion estimation when an image sequence is processed to produce an estimate of the velocity either at each points in the image or in the 3D scene, or even of the camera that produces the images.
      1. Egomotion - Determining the **3D rigid motion of the camera from an image sequence produced by the camera**.
      2. Tracking - **following the movement of a smaller set of interest points or objects vehicles, humans or other organisms in the image sequence**
      3. Optical flow - **determine, for each point in the image, how that point is moving relative to the image plane, its apparent motion**. The motion is a result both of how the corresponding 3D point is moving in the scene and how the camera is moving relative to the scene
6. Other applications
   1. Scene Reconstruction
      1. Given one or more images of a scene, or a video, it aims at computing a 3D model of the scene.
   2. Image restoration
      1. aims to remove noise from images.

## System methods

1. Functions found in many computer vision systems
   1. Image acquisition
      1. A digital image is produced by one or several image sensors, which, besides various types of light-sensitive cameras, **include range sensors, tomography devices, radar, ultra-sonic cameras, etc. Depending on the type of sensor**, the resulting image data is an ordinary 2D image, a 3D volume, or an image sequence.
      2. The **pixel values typically correspond to light intensity in one or several spectral bands** (gray images or color images), **but can also be related to various physical measures, such as depth, absorption or reflectance of sonic or electromagnetic waves, or nuclear magnetic resonance**.
   2. Pre-processing
      1. Before a computer vision method can be applied to image data in order to extract some specific piece of information, it is usually **necessary to process the data in order to assure that it satisfies certain assumptions implied by the method**.
      2. Ex
         1. re-sampling in order to assure that the image coordinate system is correct
         2. Noise reduction in order to assure that sensor noise does not introduce false information
         3. Contrast enhancement to assure that relevant information can be detected
         4. Scale space representation to enhance image structures at locally appropriate scales.
   3. Feature Extraction
      1. Image features at various levels of complexity are extracted from the image data.
      2. Ex
         1. Lines, edges and ridges
         2. Localized interest points such as corners, blobs or points.
   4. Detection/segmentation
      1. At some point in the processing a decision is made about which image points or regions of the image are relevant for further processing.
      2. Ex.
         1. **Selection of a specific set of interest points**
         2. **Segmentation of one or multiple image regions which contain a specific object of interest**.
         3. **Segmentation of image into nested scene architecture comprised foreground, object groups, single objects or salient object parts**, while the visual salience is often implemented as spatial or temporal attention.
         4. **Segmentation or co-segmentation of one or multiple videos into a series of per-frame foreground masks, while maintaining its temporal semantic continuity**.
   5. High-level processing
      1. At this step the input is typically a small set of data (points or image region which is assumed to contain a specific object). The remaining process deals with:
         1. Verification that the data satisfy model-based and application specific assumptions
         2. Estimation of application specific parameters, such as object pose or object size
         3. Image recognition (classifying a detected object into different categories)
         4. Image registration (comparing and combining two different views of the same object)
   6. Decision making
      1. Making final decision required for the application
         1. **Pass/fail on automatic inspection applications**
         2. **Match/no-match** in recognition applications
         3. **Flag for further human review** in medical, military, security and recognition applications.

## Convolutional Neural Network

1. Definition
   1. A convolutional neural network (CNN) is a class of deep neural network, most commonly applied to analyzing visual imagery.
   2. CNN uses a variation of multilayer perceptrons, known as shift invariant or space invariant artificial neural, designed to require **minimal preprocessing**.
      1. Data preprocessing includes cleaning, instance selection, normalization, transformation, feature extraction and selection, etc. The product is the final training set.
   3. CNNs were inspired by biological process in that the connectivity pattern between neurons resembles the organization of the animal visual cortex
   4. CNNs use **relatively little pre-processing compared to other image classification algorithms**. The network **learns the filters that in traditional algorithms were hand-engineered**.
      1. **This independence from prior knowledge and human effort in feature design is a major advantage**.
   5. CNNs have applications in **image and video recognition, recommender systems, image classification, medical image analysis, and natural language processing**.
2. Design
   1. A CNN consists of an input and output layer, and multiple hidden layers. The hidden layers typically consist of convolutional layers, RELU layer i.e. **activation function, pooling layers, fully connected layers and normalization layers**.
      1. Description of the process as a convolution neural network is **by convention**. Mathematically it is a cross-correlation rather than a convolution.
   2. Convolutional
      1. Convolutional layer apply a convolution operation to the input, passing the result to the next layer.
         1. Each convolutional neuron processes data only for its receptive field. Although fully connected feedforward neural networks can be used to learn features as well as classify data, it is not practical to apply this architecture to images.
   3. Pooling
      1. Pooling layers **reduce the dimensions of the data by combining the outputs of neuron clusters at one layer into a single neuron in the next layer**.
   4. Fully connected
      1. Fully connected layers connect every neuron in one layer to every neuron in another layer. it is in principle the same as the traditional multi-layer perceptron neural network (MLP). The flattened matrix goes through a fully connected layer to classify the image.
   5. Receptive field
      1. In NN, each neuron receives input from some number of locations in the previous layer.
         1. In a fully connected layer, each neuron receive input from every element of the previous layer. In a convolutional layer, **neurons receive input from only a restricted subarea of the previous layer**.
   6. Weights
      1. **Each neuron in a neural network computes an output value by applying some function to the input values coming from the receptive field in the previous layer**. The function that is applied to the input value is specified by a vector of weights and a bias. Learning a neural network progresses by making incremental adjustments to the bias and weights. The vector of weights and bias are called filter and represents some feature of the input.
         1. A distinguished feature of CNNs is that **many neurons share the same filter**. This reduces memory footprint because a single bias and a single vector of weights is used across all receptive fields sharing that filter, rather than each receptive field having its own bias and vector of weights.
3. Building Blocks
   1. What is?
      1. A CNN architecture is formed by a stack of distinct layers that transform the input volume into an output volume through a differentiable function. A few distinct types of layers are common used.
   2. Convolutional Layer
      1. Core building block.
      2. The layer's parameters consist of a set of learnable filters (or kernels), which have a small receptive field, but extend through the full depth of input volume.
         1. During the forward pass, each filter is convolved across the width and height of the input volume, computing the dot product between the entries of the filter and the input and producing a 2-dimensional activation map of that filter.
         2. As a result, the network learns filters that ativate when it detects some specific type of feature at some spatial position in the input.
   3. Local connectivity
      1. When dealing with high-dimensional inputs such as images, it's impractical to connect neurons to all neurons in the previous volume and because such a network architecture does not take the spatial structure of the data into account.
      2. **Convolutional networks exploit spatially local correlation by enforcing a sparse local connectivity pattern between neurons of adjacent layers**: each neuron connected to only a small region of the input volume.
      3. **The extent of this connectivity is a hyperparameter called the receptive field of the neuron**. The connections are local in space, but always extend along the entire depth of the input volume. Such an architecture ensures that the learnt filters produce the strongest response to a spatially local input pattern.
      4. Typical CNN architecture
         1. Image Input
         2. Convolutions => A list of feature map
         3. SubSampling => A list of f.maps times x
         4. Convolutions => A list of f.maps times x times y
         5. SubSampling => A list of f.maps times x times y times z
         6. Fully connected => output
   4. Spatial arrangement
      1. Three hyperparameters control the size of the output volume of the convolutional layer: the depth, stride and zero-padding.
         1. The depth of the output volume controls the number of neurons in a layer that connect to the same region of the input volume.
         2. Stride controls how depth columns around the spatial dimensions are allocated.
         3. Sometimes it is convenient to pad the input with zeros on the border of the input volume. The size of this padding is a third hyperparameter.
   5. Pooling layer
      1. A form of non-linear down-sampling.
      2. Serves to progressively reduce the spatial size of the representation, to reduce the number of parameters, memory footprint and amount of computation on the network, and hence also control overfitting.
      3. Important component of CNN for object detection based on fast R-CNN
   6. ReLU layer
      1. Abbreviation for rectified linear unit, which applies the non-saturating activation function. It effectively removes negative values from activation map by setting them to zero.
      2. It increases the nonlinear properties of the decision function and of the overall network without affecting the receptive fields of the convolution layer.
   7. Fully connected layer
      1. After several convolutional and max pooling layers, the high-level reasoning in the neural network is done via fully connected layers. Neurons in a fully connected layer have connections to all activiations in the previous layer, as seen in regular ANN. Their activation can thus be computed as an affine transformation, with matrix multiplication followed by a bias offset.
   8. Loss layer
      1. Specifies how training penalizes the deviation between the predicted and true labels and is normally the final layer of a neural network.
      2. Softmax loss is used for predicting a single class of K mutually exclusive classes.

## Deconvolutional neural network

1. What is
   1. A network with stacked layer, similar to convolutional neural network which alternately learns a set of filter masks and a set of activation matrices whose convolution would be equal to a given image patch.
   2. Called "deconvolutional" operation because its doing the opposite of a "convolution" operation. **Instead of convolving a filter mask with an image to get a set of activations as in a CNN** , we are trying to **guess/infer the activations that when convolved with the filter mask**, would **yield the image**.
   3. A framework that permits the unsupervised construction of hierarchical image representations. The representations can be used for both low-level tasks such as denoising, as well as providing features for object recognition. Each level of the hierarchy groups information from the level beneath to form more complex features that exist over a larger scale in the image.
   4. It seeks to generate the input signal by a sum over convolutions of the feature maps with learned filters.
2. Aims
   1. **Original aim was To learn a hierarchy of features in an unspervised manner**. However, **now its more commonly being used to invert the downsampling that takes place in a convolutional network and "expand the image back to its original size**.
      1. Basically hooking a bunch of deconvolutional layers and "unpooling" layers, using switches in the pooling layers in the convolutional part of the network which store which of the four spatial patches going into the pooling function survived; and then running gradient descent allows learning functions which couldn't be learned with a pure convolutional network, for instance for semantic segmentation.
3. From CNN to DCNN
   1. Convolution - Image goes through max pooling and convolutions many times to a fully connected layer
   2. Deconvultion - A fully connected layer which does unpooling, filter masks and activation matrices learning many times to produce a final image shape.
   3. Conclusion
      1. The CNN corresponds to feature extractor that transforms the input image to multidimensional feature representation, whereas th **deconvolution network is a shape generator that produces object segmentation from the feature extracted from the convolution network**. The **final output of the network is a probability map in the same size to the input image, indicating probability of each pixel that belongs to one of the predefined classes**.
4. Deconvolutional network to visualizing information learnt by a conv net steps
   1. Decide which filter activation you want to visualize. This could be the 15th filter in the conv4_3 layer a trained VGG conv net. This method will show you the pattern in image space that cause this activation. Hence, you should pick a filter with high magnitude activations. This is because many image patterns can cause a near-zero activation, but only some will cause a high magnitude activation. So it makes more sense to visualize a high-magnitude activation.
   2. Pass the image forward through the conv net, up to and including the layer where your chosen activation is
   3. Zero out all filter activations in the last layer except the one you want to visualize
   4. Now go back to image space, but through the devonv net. For this, "inverse" operation, three common operations seen in conv nets
      1. Unpooling: Max pooling cannot be exactly inverted. So it's proposed to remember the position of the max lower layer activation in switch variables. While going back, the activation from the upper layer is copy-pasted to the position pointed to by the switch variable, and all other lower layer activations are set ot zero.
      2. ReLU: The inverse of the ReLU function is the ReLU function. Sounds a bit odd, but since convolution is applied to rectified activation in the forward pass, deconvolution should also be applied to rectified reconstructions in the backward pass.
      3. Deconvolution: uses the same filters are the corresponding conv layer: the only difference is that they are flipped horizontally and vertically.
   5. Follow these three steps till you reach the image layer. The pattern that emerges in the image layer is the discriminative pattern that the selected activation is sensitive to.
   6. The real-world image patches are just crops of the input image, made by the receptive field of the chosen activation.
