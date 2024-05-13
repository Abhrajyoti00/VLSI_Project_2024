#pragma once 
//#include "./include/k2c_tensor_include.h"
void IMDB(float dense_1_input_input_array[10000], size_t dense_1_input_input_ndim, size_t dense_1_input_input_numel, size_t dense_1_input_input_shape[5],
               float dense_3_output_array[10000], size_t dense_3_output_ndim, size_t dense_3_output_numel, size_t dense_3_output_shape[5]);

void IMDB_initialize(); 
void IMDB_terminate(); 
