% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/nnf-fold.R
\name{nnf_fold}
\alias{nnf_fold}
\title{Fold}
\usage{
nnf_fold(
  input,
  output_size,
  kernel_size,
  dilation = 1,
  padding = 0,
  stride = 1
)
}
\arguments{
\item{input}{the input tensor}

\item{output_size}{the shape of the spatial dimensions of the output (i.e.,
\code{output$sizes()[-c(1,2)]})}

\item{kernel_size}{the size of the sliding blocks}

\item{dilation}{a parameter that controls the stride of elements within the
neighborhood. Default: 1}

\item{padding}{implicit zero padding to be added on both sides of input.
Default: 0}

\item{stride}{the stride of the sliding blocks in the input spatial dimensions.
Default: 1}
}
\description{
Combines an array of sliding local blocks into a large containing
tensor.
}
\section{Warning}{


Currently, only 4-D output tensors (batched image-like tensors) are
supported.
}

