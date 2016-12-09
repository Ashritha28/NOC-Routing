#include "LB_router.h"
#include "../../config/extern.h"


////////////////////////////////////////////////
/// fault tolerant's values in all possible direction's
////////////////////////////////////////////////
 
//int id_NN=id-(2*num_cols), id_WN=id_NW=id-num_cols-1, id_WW=id-1-1, id_EE=id+1+1, id_EN=id_NE=id+1-num_cols, id_SS=id+(2*num_cols), id_SE=id_ES=id+1+num_cols, id_SW=id_WS=id-1+num_cols;

  //******************************************                                  
                
void LB_router::setID(UI id_tile)
{
    id=id_tile;
      cout<<id+"this is tile id assighned by mechine";
    initialize();
}
        //**************** //*********************************************   
////////////////////////////////////////////////
/// Method of fault tolerant's
////////////////////////////////////////////////
//**********************************************************************************
       
                     int LB_router::getValue_W(){
                                          int flag_W=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id == fail[i][1])                               /// Cw value
						{
						    if (id_W == fail[i][0])
						    {
							flag_W=0;
						    }
                                                 }
                                               }
                            return flag_W;
                     }
                    
                       ///////////////////////////////////
                     int LB_router::getValue_N(){
                                          int flag_N=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id == fail[i][1])                               /// Cn value
						{
						    if (id_N == fail[i][0])
						    {
							flag_N=0;
						    }
                                                 }
                                               }
                            return flag_N;
                     }
                            
                                        ////////////////////
                        int LB_router::getValue_E(){
                                          int flag_E=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id == fail[i][0])                               /// Ce value
						{
						    if (id_E== fail[i][1])
						    {
							flag_E=0;
						    }
                                                 }
                                               }
                            return flag_E;
                     }
                                         
                                       ////////////////////////
                         int LB_router::getValue_S(){
                                          int flag_S=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id == fail[i][0])                               /// Cs value
						{
						    if (id_S== fail[i][1])
						    {
							flag_S=0;
						    }
                                                 }
                                               }
                            return flag_S;
                     }
     
///////***********************************************************************************************************
UI LB_router::calc_next(UI ip_dir, ULL source_id, ULL dest_id)
{
// ip_dir : input direction from packet is coming[possible values N,S,W,E]
// source_id: this is sender of packet
// dest_id: Destination of packet
//*********************************************************
        
//   Routing algorithm code here
    
     bool set_avail[4];
    for (UI i = 0; i < 4; i++)
        set_avail[i] = false;
    int cur_xco = id / num_cols;
    int cur_yco = id % num_cols;
   // int src_xco = source_id / num_cols;
   // int src_yco = source_id % num_cols;
    int dest_xco = dest_id / num_cols;
    int dest_yco = dest_id % num_cols;
    int dif_xco = dest_xco - cur_xco;
    int dif_yco = dest_yco - cur_yco;
    
  
    if(dif_xco==0 && dif_yco==0)
	    return C;
    else{
           if(dif_yco==0){
               if(dif_xco>=1 && getValue_S() && !borderS(id))
                  return S;
               else if(dif_xco<=-1 && getValue_N() && !borderN(id))
                  return N;
                }
            else if(dif_xco==0){
               if(dif_yco>=1 && getValue_E() && !borderE(id))
                  return E;
              else if(dif_yco<=-1 && getValue_W() && !borderW(id))
                  return W;
                 }
            else{
                  if(dif_xco<=-1 && dif_yco>=1){
                      if(getValue_E() && R_arr[id][2] && !borderE(id))
                        return E;
                      else if(getValue_N() && R_arr[id][0] && !borderN(id))
                        return N;
                    }
                   else if(dif_xco<=-1 && dif_yco<=-1){
                          if(getValue_W() && R_arr[id][4] && !borderW(id))
                        return W;
                         else if(getValue_N() && R_arr[id][1] && !borderN(id))
                        return N;
                    }
                   else if(dif_xco>=1 && dif_yco<=-1){
                          if(getValue_W() && R_arr[id][5] && !borderW(id))
                        return W;
                       else if(getValue_S() && R_arr[id][7] && !borderS(id))
                        return S;
                    }
                   else if(dif_xco>=1 && dif_yco>=1){
                         if(getValue_E() && R_arr[id][3] && !borderE(id))
                        	return E;
                         else if(getValue_S() && R_arr[id][6] && !borderS(id))
		                return S;
                               }
                   
                            

                  }//end of innelse
           }//end of outelse */
    } //end of method
/*
 if(dif_xco==0 && dif_yco==0)
	    return C;
    else{
           if(dif_yco==0){
               if(dif_xco>=1 && getValue_S() && ip_dir!=S && !borderS(id))
                  return S;
               else if(dif_xco<=-1 && getValue_N() && !borderN(id) && ip_dir!=N)
                  return N;
                }
            else if(dif_xco==0){
               if(dif_yco>=1 && getValue_E() && !borderE(id) && ip_dir!=E)
                  return E;
              else if(dif_yco<=-1 && getValue_W() && !borderW(id) && ip_dir!=W)
                  return W;
                 }
            else{
                  if(dif_xco<=-1 && dif_yco>=1){
                      if(getValue_E() && R_arr[id][2] && !borderE(id) && ip_dir!=E)
                        return E;
                      else if(getValue_N() && R_arr[id][0] && !borderN(id) && ip_dir!=N)
                        return N;
                    }
                   else if(dif_xco<=-1 && dif_yco<=-1){
                          if(getValue_W() && R_arr[id][4] && !borderW(id) && ip_dir!=W)
                        return W;
                         else if(getValue_N() && R_arr[id][1] && !borderN(id) && ip_dir!=N)
                        return N;
                    }
                   else if(dif_xco>=1 && dif_yco<=-1){
                          if(getValue_W() && R_arr[id][5] && !borderW(id) && ip_dir!=W)
                        return W;
                       else if(getValue_S() && R_arr[id][7] && !borderS(id) && ip_dir!=S)
                        return S;
                    }
                   else if(dif_xco>=1 && dif_yco>=1){
                         if(getValue_E() && R_arr[id][3] && !borderE(id) && ip_dir!=E)
                        	return E;
                         else if(getValue_S() && R_arr[id][6] && !borderS(id) && ip_dir!=S)
		                return S;
                               }//
                   
                            

                  }//end of innelse
           }//end of outelse */
  //  } //end of method

void LB_router::initialize()
{
       id_N = id - num_cols; id_W = id -1; id_E = id +1; id_S = id + num_cols;
   
    // id_NN=id-(2*num_cols); id_WN=id_NW=id-num_cols-1; id_WW=id-1-1; id_EE=id+1+1; id_EN=id_NE=id+1-num_cols; id_SS=id+(2*num_cols); id_SE=id_ES=id+1+num_cols; id_SW=id_WS=id-1+num_cols;

        
     /*R_arr=new int*[num_rows*num_cols];  // total num of tiles
        for( int i=0;i<num_rows*num_cols;i++)
     R_arr[i]=new int[8];   
   
      */
  
}
// for dynamic linking
extern "C"
{
    router *maker()
    {
        return new LB_router;
    }
}
	
	
