
#include <RcppMLPACK.h>				// MLPACK, Rcpp and RcppArmadillo

#include <mlpack/methods/dbscan/dbscan.hpp> 	// particular algorithm used here


//' Run a dbscan clustering analysis
//'
//' DBSCAN clustering on the data, returning number of clusters, 
//' the centroid of each cluster and also the list of cluster assignments.
//'
//' @title Run a DBSCAN clustering analysis
//' @param data A matrix of data values
//' @return assignments	Vector to store cluster assignments
//' @return centroids Matrix in which centroids are stored
//' @examples
//' x <- rbind(matrix(rnorm(100, sd = 0.3), ncol = 2),
//'            matrix(rnorm(100, mean = 1, sd = 0.3), ncol = 2))
//' colnames(x) <- c("x", "y")
//' cl <- dbscan(x)
//'
//' data(trees, package="datasets")
//' cl2 <- dbscan(t(trees))
// [[Rcpp::export]]
Rcpp::List dbscan(const arma::mat& data) {
    
    arma::Row<size_t> assignments; 		// to store results
	arma::mat centroids;
    mlpack::dbscan::DBSCAN<> dbs;    		// initialize with the default arguments.
    
    dbs.Cluster(data, &assignments, &centroids);     // make call, filling 'assignments'

    return Rcpp::List::create(Rcpp::Named("Result") = assignments,
    						  Rcpp::Named("Centroids") = centroids);
}
