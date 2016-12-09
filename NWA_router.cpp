
/*
 * NWA_router.cpp
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 *
 * Author: Lavina Jain
 *
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \file NWA_router.cpp
/// \brief Implements XY routing algorithm
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NWA_router.h"
#include "../../config/extern.h"
#include <unistd.h>

////////////////////////////////////////////////
/// fault tolerant's values in all possible direction's
////////////////////////////////////////////////
 
//int id_NN=id-(2*num_cols), id_WN=id_NW=id-num_cols-1, id_WW=id-1-1, id_EE=id+1+1, id_EN=id_NE=id+1-num_cols, id_SS=id+(2*num_cols), id_SE=id_ES=id+1+num_cols, id_SW=id_WS=id-1+num_cols;


////////////////////////////////////////////////
/// Method of fault tolerant's
////////////////////////////////////////////////
//**********************************************************************************
                     int NWA_router::getValue_W(){
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
                      //////////////////////////////////
                      int NWA_router::getValue_WW(){
                                          int flag_WW=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_W == fail[i][1])                               /// Cww value
						{
						    if (id_WW == fail[i][0])
						    {
							flag_WW=0;
						    }
                                                 }
                                               }
                            return flag_WW;
                     }
                       ///////////////////////////////////
                     int NWA_router::getValue_N(){
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
                                           ///////////////
                        int NWA_router::getValue_NN(){
                                          int flag_NN=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_N == fail[i][1])                               /// Cnn value
						{
						    if (id_NN == fail[i][0])
						    {
							flag_NN=0;
						    }
                                                 }
                                               }
                            return flag_NN;
                     }
                                        ////////////////////
                        int NWA_router::getValue_E(){
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
                                             //////////////
                              int NWA_router::getValue_EE(){
                                          int flag_EE=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_E== fail[i][0])                               /// Cee value
	                 			{
						    if (id_EE== fail[i][1])
						    {
							flag_EE=0;
						    }
                                                 }
                                               }
                            return flag_EE;
                     }
                                       ////////////////////////
                         int NWA_router::getValue_S(){
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
                                             ////////////////////////
                       int NWA_router::getValue_SS(){
                                          int flag_SS=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_S == fail[i][0])                               /// Css value
						{
						    if (id_SS== fail[i][1])
						    {
							flag_SS=0;
						    }
                                                 }
                                               }
                            return flag_SS;
                     }
                                        //////////////////////////////////
                      int NWA_router::getValue_NW(){
                                          int flag_NW=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_N == fail[i][1])                               /// Cnw value
						{
						    if ((id_N-1) == fail[i][0])
						    {
							flag_NW=0;
						    }
                                                 }
                                               }
                            return flag_NW;
                     }
                       ///////////////////////////////////
                        int NWA_router::getValue_WN(){
                                          int flag_WN=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_W== fail[i][1])                               /// Cwn value
						{
						    if ((id_W-num_cols) == fail[i][0])
						    {
							flag_WN=0;
						    }
                                                 }
                                               }
                            return flag_WN;
                     }
                       ///////////////////////////////////
                       int NWA_router::getValue_SW(){
                                          int flag_SW=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_S == fail[i][1])                               /// Csw value
						{
						    if ((id_S-1) == fail[i][0])
						    {
							flag_SW=0;
						    }
                                                 }
                                               }
                            return flag_SW;
                     }
                       ///////////////////////////////////
                        int NWA_router::getValue_WS(){
                                          int flag_WS=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_W == fail[i][0])                               /// Cws value
						{
						    if ((id_W+num_cols) == fail[i][1])
						    {
							flag_WS=0;
						    }
                                                 }
                                               }
                            return flag_WS;
                     }
                       ///////////////////////////////////
                          int NWA_router::getValue_NE(){
                                          int flag_NE=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_N == fail[i][0])                               /// Cne value
						{
						    if ((id_N+1) == fail[i][1])
						    {
							flag_NE=0;
						    }
                                                 }
                                               }
                            return flag_NE;
                     }
                       ///////////////////////////////////
                        int NWA_router::getValue_EN(){
                                          int flag_EN=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_E == fail[i][1])                               /// Cen value
						{
						    if ((id_E-num_cols) == fail[i][0])
						    {
							flag_EN=0;
						    }
                                                 }
                                               }
                            return flag_EN;
                     }
                        ///////////////////////////////////
                      int NWA_router::getValue_ES(){
                                          int flag_ES=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_E == fail[i][0])                               /// Ces value
						{
						    if ((id_E+num_cols) == fail[i][1])
						    {
							flag_ES=0;
						    }
                                                 }
                                               }
                            return flag_ES;
                     }
                      ///////////////////////////////////
                      int NWA_router::getValue_SE(){
                                          int flag_SE=1;
				              for (int i=0; i<failno ; i++)
		   			      {
						if (id_S == fail[i][0])                               /// Cse value
						{
						    if ((id_S+1) == fail[i][1])
						    {
							flag_SE=0;
						    }
                                                 }
                                               }
                            return flag_SE;
                     }

        //**************** //*********************************************



////////////////////////////////////////////////
/// Method to set unique id
////////////////////////////////////////////////
void NWA_router::setID(UI id_tile)
{
    id = id_tile;
    initialize();
}


     

////////////////////////////////////////////////
/// Method that implements XY routing
/// inherited from base class router
/// Parameters:
/// - input direction from which flit entered the tile
/// - tileID of source tile
/// - tileID of destination tile
/// returns next hop direction
////////////////////////////////////////////////
UI NWA_router::calc_next(UI ip_dir, ULL source_id, ULL dest_id)
{   
    bool set_avail[4];
    for (UI i = 0; i < 4; i++ )
        set_avail[i] = false;
    int cur_xco = id / num_cols;
    int cur_yco = id % num_cols;
    int dest_xco = dest_id / num_cols;
    int dest_yco = dest_id % num_cols;
    int src_xco = source_id / num_cols;
    int src_yco = source_id % num_cols;
    int dif_xco = dest_xco - cur_xco;
    int dif_yco = dest_yco - cur_yco;
    
   
    //curr_router_cordinates
    int xco = id / num_cols;
    int yco = id % num_cols;
    
    int dirx= ND,diry=ND; //dir's NULL

    id_N = id - num_cols; id_W = id -1; id_E = id +1; id_S = id + num_cols;
   
     id_NN=id-(2*num_cols); id_WN=id_NW=id-num_cols-1; id_WW=id-1-1; id_EE=id+1+1; id_EN=id_NE=id+1-num_cols; id_SS=id+(2*num_cols); id_SE=id_ES=id+1+num_cols; id_SW=id_WS=id-1+num_cols;
              
          if (dest_xco==xco && dest_yco==yco) 
             return C;
          else if(source_id==id){ 
		               if(dif_xco<=-1 && dif_yco==0){
		                     if(dif_xco==-1){             
		                     if(getValue_N() && !(ip_dir==N))// to avoid the cycle like n' s' that time when 3 link failed for neighbour node             
		                      return N;  }
		                     else if(getValue_N() && !(ip_dir==N) && getValue_NN()) return N;     // Cn Fnn                        
		                     else if(getValue_E() || getValue_W())                                             /////North
		                      { int f_id=fork();
				        if(f_id==0) return E;
				        else return W;
				      }
		                     else return S;
		                 }
                                else if((dif_xco>=1) && (dif_yco==0)){
		                            if(dif_xco==1){
						     if(getValue_S() && !(ip_dir==S))
						      return S; }
		                             else if(getValue_S() && !(ip_dir==S) && getValue_SS()) return S;  // cs fss  ///// South
				             else if(getValue_E() || getValue_W())         //ce cw
				              {int f_id=fork();
					       if(f_id==0) return E;
					       else return W;
					      }
				             else return N;
                                   }
                                else if(dif_xco==0 && dif_yco>=1) {
		                         if(dif_yco==1){
				                  if(getValue_E() && !(ip_dir==E))
				                   return E; }     
		                        else if(getValue_E() && !(ip_dir==E) && getValue_EE())              
		                          return E;                                 
		                         else if(getValue_N() || getValue_S())
				            {  int f_id=fork();                             ///// East
					       if(f_id==0) return N;
					       else return S;
				             }
		                         else return W;
                                     }
                                  else if(dif_xco==0 && dif_yco<=-1) {
		                         if(dif_yco==-1){
		                                  if(getValue_W() && !(ip_dir==W)) return W;}
		                         else if(getValue_W() && !(ip_dir==W) && getValue_WW()) // cw fww
		                          return W;                                                           ///// West
		                         else if(getValue_N() || getValue_S())
				            {  int f_id=fork();
					       if(f_id==0) return N;
					       else return S;
				             }
		                         else return E;
                                      }
                          else if(dif_xco<=-1 && dif_yco>=1) {       /////////// NORTH AND EAST//////       //***** N' E' *******//    
					  if(dif_xco==-1 && dif_yco==1)        ///   N1 AND E1
					    {  
						   /* if(source_id==id && !Ce && !Cn)
						    {  int f_id=fork();
						       if(f_id==0) return W;
						       else return S;
						    }
						   */////
							  if(!(ip_dir==N) && getValue_N() && getValue_NE()) //cn fne
							       return N;  
							  else if (!(ip_dir==E) && getValue_E() && getValue_EN())     // ce fen
							       return E; 
                                                  // WITH ONE HOP VISIBILITY TOWARDS NORTH AND EAST
						  else if(yco<num_cols-2) // EAST
						       {if(!(ip_dir==E) && getValue_EE() && getValue_E()) 
						       return E;}       // Fee Ce
						  else if(xco>1)     //North         
							{if(!(ip_dir==N) && getValue_NN() && getValue_N()) 
						       return N;}       // Fss Cn    
						  else if(!(ip_dir==W) && getValue_W()) 
						       return W;
						  else                         
						       return S;               //else if(Cs)
					   }
					  else if(dif_xco==-1 && dif_yco>1)         
					   {				                  ///   when nearer to x-dimention but far away to y-dime NE quad
						    if(!(ip_dir==E) && getValue_E() && (getValue_EE() || (getValue_EN())))     //     Fee Fen Ren       ///
						     return E;                         ///
						    else if(!(ip_dir==N) && getValue_N() && (getValue_NE()))       // Cn Fne Rne
						     return N;
						    else if(!(ip_dir==W) && getValue_W()) 
						       return W;
						  else                         
						       return S;               //else if(Cs)
					   }
					  else if(dif_xco<-1 && dif_yco==1)
					   {                                                 ///    nearer to y-dim but for away to x-dime  NE quad
						     if(!(ip_dir==N) && getValue_N() && (getValue_NN() || (getValue_NE()))) return N;    //       Cn Fnn Fne Rne   ///   dest is in NE quad
						     else if( !(ip_dir==E) && getValue_E() && (getValue_EN())) return E;                     // Ce fen ren
						     else if(!(ip_dir==W) && getValue_W()) 
						       return W;
						     else                         
						       return S;               //else if(Cs)
					   }
					  else if(dif_xco<-1 && dif_yco>1)
					   {
						    if(getValue_E() && !(ip_dir==E) && (getValue_EE() || (getValue_EN()))) return E;    //Ce Fee Fen Ren            //         2- HOP VISIBILITY
						    else if(getValue_N() && !(ip_dir==N) && (getValue_NN() || (getValue_NE()))) return N;         //Cn Fnn Fne Rne
						    else if(!(ip_dir==W) && getValue_W()) 
						       return W;
						  else                         
						       return S;               //else if(Cs)
					   }         ////////////////////////////////////////////// *** N' E' END *******/////////////////
			            }           
                         else if(dif_xco<=-1 && dif_yco<=-1){                   ///// NORTH AND WEST  /// ************ N' W' ******************///////////
				   if(dif_xco==-1 && dif_yco==-1)       ///   N1 & W1
				   {                               ///
				     if(!(ip_dir==N) && getValue_NW() && getValue_N()) //Fnw Rnw Cn         ///      WITH ONE HOP VISIBILITY TOWARDS NORTH AND WEST
					     return N;                   ///
				     else if(!(ip_dir==W) && getValue_WN()  && getValue_W())    //Fwn Rwn Cw
					     return W;
				     else if(yco>1) // West
				       {if(!(ip_dir==W) && getValue_WW() && getValue_W()) return W;}       // Fww Cw 
				     else if(xco>1)     //North         
					{if(!(ip_dir==N) && getValue_NN() && getValue_N()) return N;}       // Fss Cn    
				     else if(!(ip_dir==E) && getValue_E()) 
				       return E;
				     else
				       return S;
				   }
				   else if(dif_xco==-1 && dif_yco<-1)         ///   when nearer to y-dimention but far away to x-dime 
				   {				       /// 	that means dest in NW quaderant!
				    if(!(ip_dir==W) && getValue_W() && (getValue_WW() || getValue_WN()))   //Fww Fwn Rwn Cw         ///
					      return W;                         ///
				    else if(!(ip_dir==N) && getValue_N() && (getValue_NW()))  // Cn Fnw Rnw
					     return N;
				    else if(getValue_E() && !(ip_dir==E) && ip_dir==S)//!Cw !Cn
					     return E;
				    else return S;
				   }
				  else if(dif_xco<-1 && dif_yco==-1)
				   {                                                 ///    nearer to x-dim but for away to y-dime
				     if(getValue_N() && !(ip_dir==N) && (getValue_NN() || (getValue_NW())))
					   return N; //Cn Fnn Fnw Rnw      ///   dest is in NW quad
				     else if(getValue_W() && !(ip_dir==W) && getValue_WN()) 
					   return W;   //Cw Fwn Rwn
				     else if(getValue_E() && !(ip_dir==E) && ip_dir==S)//!Cw !Cn
					   return E;
				    else return S;
				   }
				  else if(dif_xco<-1 && dif_yco<-1)
				   {
				    if(!(ip_dir==W)&& getValue_W() && (getValue_WW() || (getValue_WN())))            ///Fww Fws Rws Cw
					    return W;            //         2- HOP VISIBILITY
				    else if(getValue_N() && (getValue_NN() || (getValue_NW()))) 
					    return N;               //Cn Fnn Fnw Rnw   
				     else if(getValue_E() && !(ip_dir==E)) 
					    return E;      //Cw Cn 
				     else return S;
			 
				   }      /// end of N' W' end//////////////////

			  }                                                  
                         else if(dif_xco>=1 && dif_yco<=-1){  /////SOUTH AND WEST  /// ************ S' W' ******************///////////
				 if(dif_xco==1 && dif_yco==-1)        ///   S1 & W1
				   {                               ///
				     if(!(ip_dir==S) && getValue_SW() && getValue_S()) //Fsw Rsw Cs         ///      WITH ONE HOP VISIBILITY TOWARDS NORTH AND EAST
				       return S;                   ///
				     else if(!(ip_dir==W) && getValue_WS() && getValue_W())//Fws Rws Cw
				       return W;
				     else if(yco>1)     //West
				       {if(!(ip_dir==W) && getValue_WW() && getValue_W()) return W;}//Fww Cw 
				     else if(xco<num_cols-2)          //South   
					{if(!(ip_dir==S) && getValue_SS() && getValue_S()) return S;}        //Fss Cs   
				     else if(!(ip_dir==E) && getValue_E())       // here we hv to check for source_id==id                              
				       return E;
				     else
				       return N;
				   }
				else if(dif_xco==1 && dif_yco<-1)         ///   when nearer to X-dimention but far away to Y-dime 
				   {				       /// 	that means dest in SW quaderant!
				    if(!(ip_dir==W) && (getValue_WW() || getValue_WS()) && getValue_W())   //Fww Fws Rws Cw         ///
				     return W;                         ///
				    else if(!(ip_dir==S) && getValue_S() && getValue_SW()) //Cs Fsw Rsw
				     return S;
				    else if(getValue_E() && !(ip_dir==E) && ip_dir==N)//Ce Cn
				     return E;
				    else return N;
				    }
				 else if(dif_xco>1 && dif_yco==-1)
				   {                                                 ///    nearer to Y-dim but for away to X-dime
					     if(!(ip_dir==S) && getValue_S() && (getValue_SS() || getValue_SW())) 
						return S; //Cs Fss Fsw Rsw      ///   dest is in NE quad
					     else if(!(ip_dir==W) && getValue_W() && getValue_WS())
						return W; //Cw Fws Rws
					     else if(getValue_E() && !(ip_dir==E) && ip_dir==N)//!Ce !Cn
						return E;
					    else return N;
				   }
				  else if(dif_xco>1 && dif_yco<-1)
				   {
					    if(!(ip_dir==S) && getValue_S() && (getValue_SS() || getValue_SW())) 
						  return S; //Cs Fss Fsw Rsw              //         2- HOP VISIBILITY
					    else if(!(ip_dir==W) && getValue_W() && (getValue_WW() || getValue_WS())) 
						  return W;           //Fww FWS Rws Cw      
					    else if(getValue_E() && !(ip_dir==E) && ip_dir==N)//!Ce !Cn
					     return E;
					    else return N;
				    }                 ////////////////////end of  S' W' end
			   }       
                        else if(dif_xco>=1 && dif_yco>=1) {        /////SOUTH AND EAST  /// ************ S' W' ******************///////////
			     if(dif_xco==1 && dif_yco==1)        ///   S1 & E1
				   {                               ///
					     if(!(ip_dir==S) && getValue_SE() && getValue_S())  //Fse Rse Cs        ///      WITH ONE HOP VISIBILITY TOWARDS NORTH AND EAST
						  return S;                   ///
					     else if(!(ip_dir==E) && getValue_ES() && getValue_E())//Fes Res Ce
						  return E;
					     else if(xco<num_cols-2)
					       {if(!(ip_dir==S) && getValue_SS() && getValue_S())
						  return S;}//Fss Cs
					     else if(yco<num_cols-2)             
						{if(!(ip_dir==E) && getValue_EE() && getValue_E()) 
						   return E;}        //Fee Ce   
					     else if(getValue_N() && !(ip_dir==N)) //!Ce !Cs 
						    return N;
					     else
						     return W;
				   }
			      else if(dif_xco==1 && dif_yco>1)         ///   when nearer to y-dimention but far away to x-dime 
				   {				       /// 	that means dest in NW quaderant!
					    if(!(ip_dir==E) && (getValue_EE() || getValue_ES()) && getValue_E())  //Fee Fes Res Ce          ///
					       return E;                         ///
					    else if(!(ip_dir==S) && getValue_S() && getValue_SW()) //Cs Fsw Rsw
					       return S;
					    else if(getValue_N() && !(ip_dir==N)) //!Ce !Cs 
					       return N;
					     else
					       return W;
				   }
			      else if(dif_xco>1 && dif_yco==1)
				   {                                                 ///    nearer to x-dim but for away to y-dime
					     if(!(ip_dir==S) && getValue_S() && (getValue_SS() || getValue_SE())) 
						  return S;  //Cs Fss Fse Rse     ///   dest is in NW quad
					     else if(!(ip_dir==E) && getValue_E() && getValue_ES()) 
						  return E;//Ce Fes Res
					     else if(getValue_N() && !(ip_dir==N)) //!Ce !Cs 
						  return N;
					     else
						  return W;
				   }
			       else if(dif_xco>1 && dif_yco>1)
				   {
					    if(!(ip_dir==S) && getValue_S() && (getValue_SS() || getValue_SE())) 
						   return S;//Cs Fss Fse Rse     //         2- HOP VISIBILITY
					    else if((!(ip_dir==E) && (getValue_EE() || getValue_ES()) && getValue_E()) ) //Fee Fes Res Ce          ///
						   return E;                   
					    else if(getValue_N() && !(ip_dir==N)) //!Ce !Cs 
						   return N;
					     else
						   return W;
				   }    
			    }
                }
         else{
                   if(dif_xco<=-1 && dif_yco==0){
							      if(dif_xco==-1){
								     if(getValue_N() && !(ip_dir==N))      // to avoid the cycle like n' s' that time when 3 link failed for neighbour node             
								      return N;                                      /////  North
							       }
							       else if(getValue_N() && !(ip_dir==N) && getValue_NN())
								          return N;
							       else if((getValue_E() && !(ip_dir==E)) || (getValue_W() &&!(ip_dir==W)))
								      { int f_id=fork();
									if(f_id==0 && !(ip_dir==E) && getValue_E()) return E;
									else if(getValue_W() &&!(ip_dir==W)) return W;
								        else return S;
								      }
							      else return S;
						      }   
                    else if(dif_xco==0 && dif_yco>=1) {
						         if(dif_yco==1){
						         if(getValue_E() && !(ip_dir==E))              
						          return E; }
						         else if(getValue_E() && !(ip_dir==E) && getValue_EE())             
						          return E;                                      ///// East
						         else if((getValue_N() && !(ip_dir==N)) || (getValue_S() && !(ip_dir==S)))
							    {  int f_id=fork();
							       if(f_id==0 && !(ip_dir==N) && getValue_N()) return N;
							       else if(getValue_S() &&!(ip_dir==S)) return S;
						               else return W;
							     }
						         else return W;
						}
		    else if(dif_xco==0 && dif_yco<=-1) {
						        if(dif_yco==-1){
						         if(getValue_W() && !(ip_dir==W))              
						          return W; }
						         else if(getValue_W() && !(ip_dir==W) && getValue_WW())             
						          return W;                                      ///// West
						         else if((getValue_N() && !(ip_dir==N)) || (getValue_S() && !(ip_dir==S)))
							    {  int f_id=fork();
							       if(f_id==0 && !(ip_dir==N) && getValue_N()) return N;
							       else if(getValue_S() &&!(ip_dir==S)) return S;
						               else return E;
							     }
						         else return E;
						}
		     else if(dif_xco>=1 && dif_yco==0){
						     if(dif_xco==1){
								     if(getValue_S() && !(ip_dir==S))      // to avoid the cycle like n' s' that time when 3 link failed for neighbour node             
								      return S;                           
							       }
							       else if(getValue_S() && !(ip_dir==S) && getValue_SS())
								          return N;                                         /////  South
							       else if((getValue_E() && !(ip_dir==E)) || (getValue_W() &&!(ip_dir==W)))                
								      { int f_id=fork();
									if(f_id==0 && !(ip_dir==E) && getValue_E()) return E;
									else if(getValue_W() &&!(ip_dir==W)) return W;
								        else return N;
								      }
						     else return N;
					       } 
                     else if(dif_xco<=-1 && dif_yco>=1) {       /////////// NORTH AND EAST//////       //***** N' E' *******//    
					  if(dif_xco==-1 && dif_yco==1)        ///   N1 AND E1
					    {  
						   /* if(source_id==id && !Ce && !Cn)
						    {  int f_id=fork();
						       if(f_id==0) return W;
						       else return S;
						    }
						   */////
							  if(!(ip_dir==N) && getValue_N() && getValue_NE()) //cn fne
							       return N;  
							  else if (!(ip_dir==E) && getValue_E() && getValue_EN())     // ce fen
							       return E; 
                                                  // WITH ONE HOP VISIBILITY TOWARDS NORTH AND EAST
						  else if(yco<num_cols-2) // EAST
						       {if(!(ip_dir==E) && getValue_EE() && getValue_E()) 
						       return E;}       // Fee Ce
						  else if(xco>1)     //North         
							{if(!(ip_dir==N) && getValue_NN() && getValue_N()) 
						       return N;}       // Fss Cn    
						  else if(!(ip_dir==W) && getValue_W()) 
						       return W;
						  else                         
						       return S;               //else if(Cs)
					   }
					  else if(dif_xco==-1 && dif_yco>1)         
					   {				                  ///   when nearer to x-dimention but far away to y-dime NE quad
						    if(!(ip_dir==E) && getValue_E() && (getValue_EE() || (getValue_EN())))     //     Fee Fen Ren       ///
						     return E;                         ///
						    else if(!(ip_dir==N) && getValue_N() && (getValue_NE()))       // Cn Fne Rne
						     return N;
						    else if(!(ip_dir==W) && getValue_W()) 
						       return W;
						  else                         
						       return S;               //else if(Cs)
					   }
					  else if(dif_xco<-1 && dif_yco==1)
					   {                                                 ///    nearer to y-dim but for away to x-dime  NE quad
						     if(!(ip_dir==N) && getValue_N() && (getValue_NN() || (getValue_NE()))) return N;    //       Cn Fnn Fne Rne   ///   dest is in NE quad
						     else if( !(ip_dir==E) && getValue_E() && (getValue_EN())) return E;                     // Ce fen ren
						     else if(!(ip_dir==W) && getValue_W()) 
						       return W;
						     else                         
						       return S;               //else if(Cs)
					   }
					  else if(dif_xco<-1 && dif_yco>1)
					   {
						    if(getValue_E() && !(ip_dir==E) && (getValue_EE() || (getValue_EN()))) return E;    //Ce Fee Fen Ren            //         2- HOP VISIBILITY
						    else if(getValue_N() && !(ip_dir==N) && (getValue_NN() || (getValue_NE()))) return N;         //Cn Fnn Fne Rne
						    else if(!(ip_dir==W) && getValue_W()) 
						       return W;
						  else                         
						       return S;               //else if(Cs)
					   }         ////////////////////////////////////////////// *** N' E' END *******/////////////////
			            }           
                  else if(dif_xco<=-1 && dif_yco<=-1){                   ///// NORTH AND WEST  /// ************ N' W' ******************///////////
				   if(dif_xco==-1 && dif_yco==-1)       ///   N1 & W1
				   {                               ///
				     if(!(ip_dir==N) && getValue_NW() && getValue_N()) //Fnw Rnw Cn         ///      WITH ONE HOP VISIBILITY TOWARDS NORTH AND WEST
					     return N;                   ///
				     else if(!(ip_dir==W) && getValue_WN()  && getValue_W())    //Fwn Rwn Cw
					     return W;
				     else if(yco>1) // West
				       {if(!(ip_dir==W) && getValue_WW() && getValue_W()) return W;}       // Fww Cw 
				     else if(xco>1)     //North         
					{if(!(ip_dir==N) && getValue_NN() && getValue_N()) return N;}       // Fss Cn    
				     else if(!(ip_dir==E) && getValue_E()) 
				       return E;
				     else
				       return S;
				   }
				   else if(dif_xco==-1 && dif_yco<-1)         ///   when nearer to y-dimention but far away to x-dime 
				   {				       /// 	that means dest in NW quaderant!
				    if(!(ip_dir==W) && getValue_W() && (getValue_WW() || getValue_WN()))   //Fww Fwn Rwn Cw         ///
					      return W;                         ///
				    else if(!(ip_dir==N) && getValue_N() && (getValue_NW()))  // Cn Fnw Rnw
					     return N;
				    else if(getValue_E() && !(ip_dir==E) && ip_dir==S)//!Cw !Cn
					     return E;
				    else return S;
				   }
				  else if(dif_xco<-1 && dif_yco==-1)
				   {                                                 ///    nearer to x-dim but for away to y-dime
				     if(getValue_N() && !(ip_dir==N) && (getValue_NN() || (getValue_NW())))
					   return N; //Cn Fnn Fnw Rnw      ///   dest is in NW quad
				     else if(getValue_W() && !(ip_dir==W) && getValue_WN()) 
					   return W;   //Cw Fwn Rwn
				     else if(getValue_E() && !(ip_dir==E) && ip_dir==S)//!Cw !Cn
					   return E;
				    else return S;
				   }
				  else if(dif_xco<-1 && dif_yco<-1)
				   {
				    if(!(ip_dir==W)&& getValue_W() && (getValue_WW() || (getValue_WN())))            ///Fww Fws Rws Cw
					    return W;            //         2- HOP VISIBILITY
				    else if(getValue_N() && (getValue_NN() || (getValue_NW()))) 
					    return N;               //Cn Fnn Fnw Rnw   
				     else if(getValue_E() && !(ip_dir==E)) 
					    return E;      //Cw Cn 
				     else return S;
			 
				   }      /// end of N' W' end//////////////////

			  }                                                  
                 else if(dif_xco>=1 && dif_yco<=-1){  /////SOUTH AND WEST  /// ************ S' W' ******************///////////
				 if(dif_xco==1 && dif_yco==-1)        ///   S1 & W1
				   {                               ///
				     if(!(ip_dir==S) && getValue_SW() && getValue_S()) //Fsw Rsw Cs         ///      WITH ONE HOP VISIBILITY TOWARDS NORTH AND EAST
				       return S;                   ///
				     else if(!(ip_dir==W) && getValue_WS() && getValue_W())//Fws Rws Cw
				       return W;
				     else if(yco>1)     //West
				       {if(!(ip_dir==W) && getValue_WW() && getValue_W()) return W;}//Fww Cw 
				     else if(xco<num_cols-2)          //South   
					{if(!(ip_dir==S) && getValue_SS() && getValue_S()) return S;}        //Fss Cs   
				     else if(!(ip_dir==E) && getValue_E())       // here we hv to check for source_id==id                              
				       return E;
				     else
				       return N;
				   }
				else if(dif_xco==1 && dif_yco<-1)         ///   when nearer to X-dimention but far away to Y-dime 
				   {				       /// 	that means dest in SW quaderant!
				    if(!(ip_dir==W) && (getValue_WW() || getValue_WS()) && getValue_W())   //Fww Fws Rws Cw         ///
				     return W;                         ///
				    else if(!(ip_dir==S) && getValue_S() && getValue_SW()) //Cs Fsw Rsw
				     return S;
				    else if(getValue_E() && !(ip_dir==E) && ip_dir==N)//Ce Cn
				     return E;
				    else return N;
				    }
				 else if(dif_xco>1 && dif_yco==-1)
				   {                                                 ///    nearer to Y-dim but for away to X-dime
					     if(!(ip_dir==S) && getValue_S() && (getValue_SS() || getValue_SW())) 
						return S; //Cs Fss Fsw Rsw      ///   dest is in NE quad
					     else if(!(ip_dir==W) && getValue_W() && getValue_WS())
						return W; //Cw Fws Rws
					     else if(getValue_E() && !(ip_dir==E) && ip_dir==N)//!Ce !Cn
						return E;
					    else return N;
				   }
				  else if(dif_xco>1 && dif_yco<-1)
				   {
					    if(!(ip_dir==S) && getValue_S() && (getValue_SS() || getValue_SW())) 
						  return S; //Cs Fss Fsw Rsw              //         2- HOP VISIBILITY
					    else if(!(ip_dir==W) && getValue_W() && (getValue_WW() || getValue_WS())) 
						  return W;           //Fww FWS Rws Cw      
					    else if(getValue_E() && !(ip_dir==E) && ip_dir==N)//!Ce !Cn
					     return E;
					    else return N;
				    }                 ////////////////////end of  S' W' end
			   }       
                  else if(dif_xco>=1 && dif_yco>=1) {        /////SOUTH AND EAST  /// ************ S' W' ******************///////////
			     if(dif_xco==1 && dif_yco==1)        ///   S1 & E1
				   {                               ///
					     if(!(ip_dir==S) && getValue_SE() && getValue_S())  //Fse Rse Cs        ///      WITH ONE HOP VISIBILITY TOWARDS NORTH AND EAST
						  return S;                   ///
					     else if(!(ip_dir==E) && getValue_ES() && getValue_E())//Fes Res Ce
						  return E;
					     else if(xco<num_cols-2)
					       {if(!(ip_dir==S) && getValue_SS() && getValue_S())
						  return S;}//Fss Cs
					     else if(yco<num_cols-2)             
						{if(!(ip_dir==E) && getValue_EE() && getValue_E()) 
						   return E;}        //Fee Ce   
					     else if(getValue_N() && !(ip_dir==N)) //!Ce !Cs 
						    return N;
					     else
						     return W;
				   }
			      else if(dif_xco==1 && dif_yco>1)         ///   when nearer to y-dimention but far away to x-dime 
				   {				       /// 	that means dest in NW quaderant!
					    if(!(ip_dir==E) && (getValue_EE() || getValue_ES()) && getValue_E())  //Fee Fes Res Ce          ///
					       return E;                         ///
					    else if(!(ip_dir==S) && getValue_S() && getValue_SW()) //Cs Fsw Rsw
					       return S;
					    else if(getValue_N() && !(ip_dir==N)) //!Ce !Cs 
					       return N;
					     else
					       return W;
				   }
			      else if(dif_xco>1 && dif_yco==1)
				   {                                                 ///    nearer to x-dim but for away to y-dime
					     if(!(ip_dir==S) && getValue_S() && (getValue_SS() || getValue_SE())) 
						  return S;  //Cs Fss Fse Rse     ///   dest is in NW quad
					     else if(!(ip_dir==E) && getValue_E() && getValue_ES()) 
						  return E;//Ce Fes Res
					     else if(getValue_N() && !(ip_dir==N)) //!Ce !Cs 
						  return N;
					     else
						  return W;
				   }
			       else if(dif_xco>1 && dif_yco>1)
				   {
					    if(!(ip_dir==S) && getValue_S() && (getValue_SS() || getValue_SE())) 
						   return S;//Cs Fss Fse Rse     //         2- HOP VISIBILITY
					    else if((!(ip_dir==E) && (getValue_EE() || getValue_ES()) && getValue_E()) ) //Fee Fes Res Ce          ///
						   return E;                   
					    else if(getValue_N() && !(ip_dir==N)) //!Ce !Cs 
						   return N;
					     else
						   return W;
				   }    
			    }//end of S' E'
                             
               }   // end of else  
       return 0;
   }//end of the method
       //************************************************

 ////////////////////////////////////////////////
/// Method containing any initializations
/// inherited from base class router
////////////////////////////////////////////////
// may be empty
// definition must be included even if empty, because this is a virtual function in base class
void NWA_router::initialize()
{

}

// for dynamic linking
extern "C"
{
    router *maker()
    {
        return new NWA_router;
    }
}

    /*
    int choose=0; // 0 for X-dir and 1 for Y-dir

    int markx=0, marky=0;
   
    if (dest_xco == xco && dest_yco == yco)
        return C;

    if (dest_yco > yco)
        dirx= E;
    else if (dest_yco < yco)
        dirx= W;

    if (dest_xco < xco)
        diry= N;
    else if (dest_xco > xco)
        diry= S;

    //if the node itself is a marked node
    for (int i=0; i<failno ; i++)
    {
        if (id == fail[i][0])
        {
            if (id_E == fail[i][1] && dirx == E)
            {
                dirx=ND;
            }
            if (id_S == fail[i][1] && diry == S)
            {
                diry=ND;
            }
        }
        if (id == fail[i][1])
        {
            if (id_W == fail[i][0] && dirx == W)
            {
                dirx=ND;
            }
            if (id_N == fail[i][0] && diry == N)
            {
                diry=ND;
            }
        }
    }

    // end self marked node check

    if (dirx== ND)
        return diry;
    if (diry== ND)
        return dirx;

    // Mark nodes in the x direction
    if (dirx == E)
    {
        for (int i=0; i<failno ; i++)
        {
            if (id_E == fail[i][0] || id_E == fail[i][1])
            {
                markx = 1;
            }

        }
    }
    else if (dirx == W)
    {
        for (int i=0; i<failno ; i++)
        {
            if (id_W == fail[i][0] || id_W == fail[i][1])
            {
                markx = 1;
            }

        }
    }

    // Mark nodes in the y direction

    if (diry == N)
    {
        for (int i=0; i<failno ; i++)
        {
            if (id_N == fail[i][0] || id_N == fail[i][1])
            {
                marky = 1;
            }
        }
    }
    else if (diry == S)
    {
        for (int i=0; i<failno ; i++)
        {
            if (id_S == fail[i][0] || id_S == fail[i][1])
            {
                marky = 1;
            }

        }
    }

    if (markx==0 && marky==0)
    {
        choose=(id%2);
    }

    if (markx==0 && marky==1)
    {
        choose=0;
    }
    if (markx==1 && marky==0)
    {
        choose=1;
    }
    if (markx==1 && marky==1)
    {
        choose=(id%2);
    }
//	cout<<"\nTile ID "<<id<<"CHOSEN DIR "<< choose<< " dirX= "<< dirx << " dirY= " << diry<<"\n";

    switch (choose)
    {
    case 0:
        return dirx;
        break;
    case 1:
        return diry;
        break;
    }
    return 0;
}
*/

