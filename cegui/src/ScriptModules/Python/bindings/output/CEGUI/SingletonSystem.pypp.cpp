// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUI.h"
#include "SingletonSystem.pypp.hpp"

namespace bp = boost::python;

void register_SingletonSystem_class(){

    { //::CEGUI::Singleton< CEGUI::System >
        typedef bp::class_< CEGUI::Singleton< CEGUI::System >, boost::noncopyable > SingletonSystem_exposer_t;
        SingletonSystem_exposer_t SingletonSystem_exposer = SingletonSystem_exposer_t( "SingletonSystem", bp::init< >() );
        bp::scope SingletonSystem_scope( SingletonSystem_exposer );
        { //::CEGUI::Singleton< CEGUI::System >::getSingleton
        
            typedef CEGUI::Singleton< CEGUI::System > exported_class_t;
            typedef ::CEGUI::System & ( *getSingleton_function_type )(  );
            
            SingletonSystem_exposer.def( 
                "getSingleton"
                , getSingleton_function_type( &::CEGUI::Singleton< CEGUI::System >::getSingleton )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        SingletonSystem_exposer.staticmethod( "getSingleton" );
    }

}
