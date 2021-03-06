// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUI.h"
#include "SimpleTimer.pypp.hpp"

namespace bp = boost::python;

void register_SimpleTimer_class(){

    { //::CEGUI::SimpleTimer
        typedef bp::class_< CEGUI::SimpleTimer > SimpleTimer_exposer_t;
        SimpleTimer_exposer_t SimpleTimer_exposer = SimpleTimer_exposer_t( "SimpleTimer", bp::init< >() );
        bp::scope SimpleTimer_scope( SimpleTimer_exposer );
        { //::CEGUI::SimpleTimer::currentTime
        
            typedef double ( *currentTime_function_type )(  );
            
            SimpleTimer_exposer.def( 
                "currentTime"
                , currentTime_function_type( &::CEGUI::SimpleTimer::currentTime )
                , "! returns time in seconds\n" );
        
        }
        { //::CEGUI::SimpleTimer::elapsed
        
            typedef double ( ::CEGUI::SimpleTimer::*elapsed_function_type )(  ) ;
            
            SimpleTimer_exposer.def( 
                "elapsed"
                , elapsed_function_type( &::CEGUI::SimpleTimer::elapsed ) );
        
        }
        { //::CEGUI::SimpleTimer::restart
        
            typedef void ( ::CEGUI::SimpleTimer::*restart_function_type )(  ) ;
            
            SimpleTimer_exposer.def( 
                "restart"
                , restart_function_type( &::CEGUI::SimpleTimer::restart ) );
        
        }
        SimpleTimer_exposer.staticmethod( "currentTime" );
    }

}
