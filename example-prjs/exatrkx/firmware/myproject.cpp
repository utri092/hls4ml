//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include <iostream>

#include "myproject.h"
#include "parameters.h"

void myproject(
	       input_t      X[N_NODES][N_NODE_FEATURES],
	       input_t      Y[N_EDGES][N_EDGE_FEATURES],
	       adjacency_t  Rr[N_EDGES][1],
	       adjacency_t  Rs[N_EDGES][1],
	       result_t     e[N_EDGES][1],
	       unsigned short &const_size_in,
	       unsigned short &const_size_out)
{
  
  //hls-fpga-machine-learning insert IO
  //#pragma HLS ARRAY_RESHAPE variable=X complete dim=0 
  //#pragma HLS ARRAY_RESHAPE variable=Y complete dim=0 
  //#pragma HLS ARRAY_RESHAPE variable=Rr complete dim=0 
  //#pragma HLS ARRAY_RESHAPE variable=Rs complete dim=0 
  //#pragma HLS ARRAY_RESHAPE variable=e complete dim=0 
#pragma HLS INTERFACE ap_vld port=X,Rr,Rs,e
  //#pragma HLS PIPELINE 
  
  
  const_size_in   = N_NODES*N_NODE_FEATURES+N_EDGES*N_EDGE_FEATURES+2*N_EDGES;
  const_size_out  = N_EDGES*1;
  

  // implement network here
}
