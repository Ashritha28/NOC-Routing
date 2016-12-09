
/*
 * XY_router.h
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
/// \file NWA_router.h
/// \brief Defines class to implement XY routing algorithm
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __NWA_router__
#define __NWA_router__

#include "../../core/router.h"

//////////////////////////////////////////////////////////////////////
/// \brief Class to implement XY routing algorithm
///
/// inherited from from class router
//////////////////////////////////////////////////////////////////////
class NWA_router : public router {
	public:
                     /// fault
                  int id_N, id_W, id_E, id_S;
                int id_NN, id_WN,id_NW, id_WW, id_EE, id_EN,id_NE, id_SS, id_SE,id_ES, id_SW,id_WS;
		/// Constructor
		NWA_router() { }
		
		/// returns next hop for a given source and destination. ip_dir is the incoming direction
		UI calc_next(UI ip_dir, ULL source_id, ULL dest_id);
		
		void initialize();	///< any initializations to be done
		void setID(UI tileid);	///< set unique id
		UI get_estimate(UI){}
		void update_estimate(UI,UI,UI,ULL){}
		void update_power(int,double ){}
                 /*  //Fault's in Mesh Topology
                int getValue_N();
                int getValue_E();
                int getValue_W();
                int getValue_S();
                int getValue_NN();
                int getValue_EE();
                int getValue_WW();
                int getValue_SS();
                int getValue_NW();
                int getValue_NE();
                int getValue_EN();
                int getValue_ES();
                int getValue_WN();
                int getValue_WS();
                int getValue_SE();
                int getValue_SW();
                 */                   //Fault's in Mesh Topology
                int getValue_N();
                int getValue_E();
                int getValue_W();
                int getValue_S();
                int getValue_NN();
                int getValue_EE();
                int getValue_WW();
                int getValue_SS();
                int getValue_NW();
                int getValue_NE();
                int getValue_EN();
                int getValue_ES();
                int getValue_WN();
                int getValue_WS();
                int getValue_SE();
                int getValue_SW();
		
		
};

#endif

