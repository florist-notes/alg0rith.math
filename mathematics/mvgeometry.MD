# Multiple View Geometry:

Multi-view geometry is a fundamental concept in computer vision that deals with the mathematical relationships between multiple views (images) of the same scene. It plays a crucial role in tasks like 3D reconstruction, stereo vision, structure from motion, and object tracking.

+ <b>Epipolar Geometry:</b> Epipolar geometry is the geometry of multiple views of a 3D scene, defined by the epipolar line, epipolar plane, and the essential matrix. The essential matrix relates the camera poses and intrinsic parameters between two views.

+ <b>Fundamental Matrix:</b> The fundamental matrix encodes the epipolar geometry between two images. It describes the relationship between points in one image and their corresponding epipolar lines in the other image.

+ <b>Triangulation:</b> Triangulation is the process of estimating the 3D position of a point in the scene using its corresponding 2D projections in multiple images. It is based on the intersection of corresponding rays.

+ <b>Camera Projection:</b> The camera projection model relates 3D world points to 2D image points using camera calibration parameters, such as the camera's intrinsic matrix and distortion coefficients.

In this code example, we'll use OpenCV to perform a basic multi-view geometry task: finding corresponding points between two images and estimating the fundamental matrix. 

```cpp

#include <opencv2/opencv.hpp>
#include <vector>

int main() {
    // Load two images
    cv::Mat image1 = cv::imread("image1.png", cv::IMREAD_GRAYSCALE);
    cv::Mat image2 = cv::imread("image2.png", cv::IMREAD_GRAYSCALE);

    if (image1.empty() || image2.empty()) {
        std::cerr << "Error: Unable to load images." << std::endl;
        return -1;
    }

    // Detect and match keypoints between images (e.g., using SIFT)
    cv::Ptr<cv::Feature2D> detector = cv::SIFT::create();
    std::vector<cv::KeyPoint> keypoints1, keypoints2;
    cv::Mat descriptors1, descriptors2;

    detector->detectAndCompute(image1, cv::Mat(), keypoints1, descriptors1);
    detector->detectAndCompute(image2, cv::Mat(), keypoints2, descriptors2);

    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);
    std::vector<cv::DMatch> matches;
    matcher->match(descriptors1, descriptors2, matches);

    // Extract matched keypoints
    std::vector<cv::Point2f> points1, points2;
    for (const cv::DMatch& match : matches) {
        points1.push_back(keypoints1[match.queryIdx].pt);
        points2.push_back(keypoints2[match.trainIdx].pt);
    }

    // Estimate fundamental matrix
    cv::Mat fundamentalMatrix = cv::findFundamentalMat(points1, points2, cv::FM_RANSAC);

    std::cout << "Fundamental Matrix:" << std::endl << fundamentalMatrix << std::endl;

    return 0;
}


```

In this code:

+ We load two images and detect keypoints and descriptors (e.g., SIFT features) in both images.

+ We match keypoints between the two images using a descriptor matcher.

+ We extract the matched keypoints' 2D coordinates.

+ Using the matched points, we estimate the fundamental matrix using the RANSAC algorithm.

+ Finally, we print the estimated fundamental matrix.

Correspondence between 2D and 2D, 2D and 3D, and 3D and 3D points is a fundamental concept in multi-view geometry. It plays a crucial role in various computer vision tasks such as structure from motion, stereo vision, and object tracking. 

### Correspondence between 2D and 2D Points:

In multi-view geometry, establishing correspondences between 2D points in different images is a common task. The goal is to find pairs of points that represent the same physical point in the 3D world. This correspondence is typically used in tasks like feature matching and stereo vision.

Here's a code example using OpenCV to find correspondences between 2D points in two images:


```cpp

#include <opencv2/opencv.hpp>

int main() {
    // Load two images
    cv::Mat image1 = cv::imread("image1.png", cv::IMREAD_GRAYSCALE);
    cv::Mat image2 = cv::imread("image2.png", cv::IMREAD_GRAYSCALE);

    if (image1.empty() || image2.empty()) {
        std::cerr << "Error: Unable to load images." << std::endl;
        return -1;
    }

    // Detect and match keypoints between images (e.g., using SIFT)
    cv::Ptr<cv::Feature2D> detector = cv::SIFT::create();
    std::vector<cv::KeyPoint> keypoints1, keypoints2;
    cv::Mat descriptors1, descriptors2;

    detector->detectAndCompute(image1, cv::Mat(), keypoints1, descriptors1);
    detector->detectAndCompute(image2, cv::Mat(), keypoints2, descriptors2);

    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);
    std::vector<cv::DMatch> matches;
    matcher->match(descriptors1, descriptors2, matches);

    // Extract matched keypoints
    std::vector<cv::Point2f> points1, points2;
    for (const cv::DMatch& match : matches) {
        points1.push_back(keypoints1[match.queryIdx].pt);
        points2.push_back(keypoints2[match.trainIdx].pt);
    }

    // Now, points1 and points2 contain the corresponding 2D points in both images
    return 0;
}



```

### Correspondence between 2D and 3D Points:

Correspondence between 2D and 3D points is crucial in applications like structure from motion (SfM) and camera pose estimation. In SfM, 2D image points are related to 3D world points through the camera projection matrix.

Here's a code example that demonstrates correspondence between 2D and 3D points:

```cpp

#include <opencv2/opencv.hpp>
#include <vector>

int main() {
    // Load camera intrinsic matrix (K)
    cv::Mat K = (cv::Mat_<double>(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);

    // Load 2D image points
    std::vector<cv::Point2f> imagePoints = {cv::Point2f(x1, y1), cv::Point2f(x2, y2), /*...*/};

    // Corresponding 3D world points
    std::vector<cv::Point3f> worldPoints = {cv::Point3f(X1, Y1, Z1), cv::Point3f(X2, Y2, Z2), /*...*/};

    // Perform camera pose estimation to find 3D-2D correspondences
    cv::Mat rvec, tvec;
    cv::solvePnP(worldPoints, imagePoints, K, cv::Mat(), rvec, tvec);

    // Now, rvec and tvec contain the rotation and translation of the camera
    return 0;
}


```

#### PnP (Perspective-n-Point) Pose Estimation:

PnP is a generalization of P3P and can handle more than three corresponding points for camera pose estimation. OpenCV provides various algorithms for PnP, including EPnP and APnP.

Here's a code example using OpenCV to perform PnP pose estimation:

```cpp

#include <opencv2/opencv.hpp>

int main() {
    // Define 3D world points and their corresponding 2D image points
    std::vector<cv::Point3d> worldPoints;
    std::vector<cv::Point2d> imagePoints;

    // Populate worldPoints and imagePoints with corresponding 3D and 2D points

    // Camera intrinsic matrix
    cv::Mat K = (cv::Mat_<double>(3, 3) << fx, 0, cx, 0, fy, cy, 0, 0, 1);

    // Solve for pose using PnP (e.g., EPnP or APnP)
    cv::Mat rvec, tvec;
    cv::solvePnP(worldPoints, imagePoints, K, cv::Mat(), rvec, tvec, true);

    // rvec and tvec now contain the rotation and translation vectors
    return 0;
}


```

### Correspondence between 3D and 3D Points:

Establishing correspondence between 3D points in different views is a fundamental step in multi-view stereo (MVS) reconstruction and 3D object tracking. This correspondence allows you to triangulate 3D points from multiple views.

Here's a code example that demonstrates correspondence between 3D points:

```cpp

#include <opencv2/opencv.hpp>
#include <vector>

int main() {
    // Load 3D points from two different views
    std::vector<cv::Point3f> pointsView1 = {cv::Point3f(X1, Y1, Z1), cv::Point3f(X2, Y2, Z2), /*...*/};
    std::vector<cv::Point3f> pointsView2 = {cv::Point3f(X1', Y1', Z1'), cv::Point3f(X2', Y2', Z2'), /*...*/};

    // Perform correspondence matching (e.g., using feature matching or point-to-point matching)
    // You can use various algorithms to establish 3D-3D correspondences based on your application

    // Now, you have correspondences between 3D points in different views
    return 0;
}


```

#### ICP (Iterative Closest Point) Point Cloud Alignment:

ICP is an iterative algorithm used for aligning two point clouds, typically with a known transformation between them. It iteratively refines the transformation to minimize the distance between corresponding points in the two point clouds.

Here's a code example using the Point Cloud Library (PCL) for ICP point cloud alignment:

```cpp
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>

int main() {
    // Load two point clouds
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);
    
    pcl::io::loadPCDFile("cloud1.pcd", *cloud1);
    pcl::io::loadPCDFile("cloud2.pcd", *cloud2);

    // Create ICP object
    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    icp.setInputSource(cloud1);
    icp.setInputTarget(cloud2);

    // Align the two point clouds
    pcl::PointCloud<pcl::PointXYZ> finalCloud;
    icp.align(finalCloud);

    // The transformation matrix is available through icp.getFinalTransformation()
    
    return 0;
}


```
### Outlier Rejection in Multiple View Geometry:

In multiple view geometry, outlier rejection is the process of identifying and removing incorrect correspondences or data points that do not conform to the expected geometric relationships. Outliers can result from factors like noise in measurements, occlusions, or mismatches. Removing outliers is essential to ensure the accuracy and robustness of geometric computations, such as camera pose estimation or point cloud registration.

### RANSAC (Random Sample Consensus):

RANSAC is a widely used algorithm for outlier rejection in computer vision and multiple view geometry. It works by iteratively fitting models to a subset of the data (inliers) while identifying and removing outliers. The steps of the RANSAC algorithm are as follows:

+ Randomly select a minimal subset of data points to form a model.

+ Fit a model to the selected subset (e.g., estimate a transformation).

+ Compute the error or residual for all data points.

+ Identify data points whose error is below a predefined threshold as inliers.

+ Repeat the process for a fixed number of iterations or until a sufficient number of inliers are found.

+ Select the model with the largest number of inliers as the best estimate.

+ Refit the model to all inliers.

In this code example, we will use OpenCV to demonstrate RANSAC for outlier rejection in the context of estimating a 2D similarity transformation (e.g., affine transformation) between two sets of points. This is a simplified example, but the RANSAC framework can be applied to various geometric transformations.

```cpp

#include <opencv2/opencv.hpp>

int main() {
    // Generate two sets of random points (with some outliers)
    int numPoints = 100;
    cv::Mat srcPoints(2, numPoints, CV_32FC1);
    cv::Mat dstPoints(2, numPoints, CV_32FC1);

    for (int i = 0; i < numPoints; ++i) {
        srcPoints.at<float>(0, i) = float(rand() % 100);
        srcPoints.at<float>(1, i) = float(rand() % 100);

        // Introduce some outliers
        if (i % 10 == 0) {
            dstPoints.at<float>(0, i) = float(rand() % 100);
            dstPoints.at<float>(1, i) = float(rand() % 100);
        } else {
            dstPoints.at<float>(0, i) = srcPoints.at<float>(0, i) + 2.0f;
            dstPoints.at<float>(1, i) = srcPoints.at<float>(1, i) + 2.0f;
        }
    }

    // Use RANSAC to estimate a similarity transformation
    cv::Mat inliersMask;
    cv::Mat transformation = cv::estimateAffine2D(srcPoints, dstPoints, inliersMask);

    // Extract inliers based on the mask
    std::vector<cv::Point2f> inliersSrc, inliersDst;
    for (int i = 0; i < numPoints; ++i) {
        if (inliersMask.at<uchar>(i)) {
            inliersSrc.push_back(cv::Point2f(srcPoints.at<float>(0, i), srcPoints.at<float>(1, i)));
            inliersDst.push_back(cv::Point2f(dstPoints.at<float>(0, i), dstPoints.at<float>(1, i)));
        }
    }

    // Display inliers and estimated transformation
    cv::Mat resultImage;
    cv::drawMatches(srcImage, inliersSrc, dstImage, inliersDst, inliersMatches, resultImage);
    cv::imshow("Inliers", resultImage);
    cv::waitKey(0);

    return 0;
}


```

In this code:

+ We generate two sets of random points, one of which has some outliers introduced by adding random noise.

+ We use the `cv::estimateAffine2D` function from OpenCV to estimate a 2D similarity transformation (affine transformation) between the two point sets while identifying inliers using RANSAC.

+ Inliers are extracted based on the inliers mask obtained from RANSAC.

+ We visualize the inliers and the estimated transformation.

resources: [Multiple View Geometry (Prof. D. Cremers)](), [Multiple View Geometry in Computer Vision](https://www.youtube.com/playlist?list=PLTBdjV_4f-EJn6udZ34tht9EVIW7lbeo4), [3D Computer Vision  : NUS](https://www.youtube.com/playlist?list=PLxg0CGqViygP47ERvqHw_v7FVnUovJeaz).