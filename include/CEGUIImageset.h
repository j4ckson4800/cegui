/************************************************************************
	filename: 	CEGUIImageset.h
	created:	21/2/2004
	author:		Paul D Turner
	
	purpose:	Defines the interface for the Imageset class
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://crayzedsgui.sourceforge.net)
    Copyright (C)2004 Paul D Turner (crayzed@users.sourceforge.net)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#ifndef _CEGUIImageset_h_
#define _CEGUIImageset_h_

#include "CEGUIBase.h"
#include "CEGUIString.h"
#include "CEGUIRect.h"
#include "CEGUIColourRect.h"
#include "CEGUIImagesetManager.h"
#include "CEGUIImage.h"

#include <map>


// Start of CEGUI namespace section
namespace CEGUI
{

/*!
\brief
	Offers functions to define, access, and draw, a set of image components on a single graphical surface or Texture.

	Imageset objects are a means by which a single graphical image (file, Texture, etc), can be split into a number
	of 'components' which can later be accessed via name.  The components of an Imageset can queried for
	various details, and sent to the Renderer object for drawing.
*/
class CEGUIBASE_API Imageset
{
	friend class Imageset_xmlHandler;
private:
	/*************************************************************************
		Friends to allow access to constructors and destructors
	*************************************************************************/
	friend Imageset*	ImagesetManager::createImageset(const String& name, Texture* texture);
	friend Imageset*	ImagesetManager::createImageset(const String& filename);
	friend void			ImagesetManager::destroyImageset(const String& name);


	/*************************************************************************
		Construction and Destruction (private, only ImagesetManager can 
		create and destroy Imageset objects).
	*************************************************************************/
	/*!
	\brief
		Construct a new Imageset object.  Object will initially have no Images defined

	\param texture
		Texture object that holds the imagery for the Imageset being created.
	*/
	Imageset(const String& name, Texture* texture);


	/*!
	\brief
		Construct a new Imageset object using data contained in the specified file.

	\param filename
		String object that holds the name of the Imageset data file that is to be processed.

	\exception	FileIOException		thrown if something goes wrong while processing the file \a filename.
	*/
	Imageset(const String& filename);


	/*!
	\brief
		Destroys Imageset objects
	*/
	~Imageset(void);


public:
	/*************************************************************************
		Public interface
	*************************************************************************/
	/*!
	\brief
		return Texture object for this Imageset

	\return
		Texture object that holds the imagery for this Imageset
	*/
	Texture*	getTexture(void) const						{return d_texture;}


	/*!
	\brief
		return String object holding the name of the Imageset

	\return	
		String object that holds the name of the Imageset.
	*/
	const String&	getName(void) const						{return d_name;}


	/*!
	\brief
		return number of images defined for this Imageset

	\return
		uint value equal to the number of Image objects defined for the Imageset
	*/
	uint      getImageCount(void) const               {return (uint)d_images.size();}

 
	/*!
	\brief
		return true if an Image with the specified name exists.

	\param name
		String object holding the name of the Image to look for.

	\return
		true if an Image object named \a name is defined for this Imageset, else false.
	*/
	bool		isImageDefined(const String& name) const	{return d_images.find(name) != d_images.end();}

 
	/*!
	\brief
		return a copy of the Image object for the named image

	\param name
		String object holding the name of the Image object to be returned

	\return
		constant Image object that has the requested name.

	\exception UnknownObjectException	thrown if no Image named \a name is defined for the Imageset
	*/
	const Image&	getImage(const String& name) const;


	/*!
	\brief
		remove the definition for the Image with the specified name.  If no such Image exists, nothing happens.

	\param name
		String object holding the name of the Image object to be removed from the Imageset,
	\return
		Nothing.
	*/
	void	undefineImage(const String& name)				{d_images.erase(name);}


	/*!
	\brief
		Removes the definitions for all Image objects currently defined in the Imageset

	\return
		Nothing
	*/
	void	undefineAllImages(void)							{d_images.clear();}


	/*!
	\brief
		return a Size object describing the dimensions of the named image.

	\param name
		String object holding the name of the Image.

	\return
		Size object holding the dimensions of the requested Image.

	\exception UnknownObjectException	thrown if no Image named \a name is defined for the Imageset
	*/
	Size	getImageSize(const String& name) const			{return getImage(name).getSize();}


	/*!
	\brief
		return the width of the named image.

	\param name
		String object holding the name of the Image.

	\return
		float value equalling the width of the requested Image.

	\exception UnknownObjectException	thrown if no Image named \a name is defined for the Imageset
	*/
	float	getImageWidth(const String& name) const			{return getImage(name).getWidth();}


	/*!
	\brief
		return the height of the named image.

	\param name
		String object holding the name of the Image.

	\return
		float value equalling the height of the requested Image.

	\exception UnknownObjectException	thrown if no Image named \a name is defined for the Imageset
	*/
	float	getImageHeight(const String& name) const		{return getImage(name).getHeight();}


	/*!
	\brief
		return the rendering offsets applied to the named image.

	\param name
		String object holding the name of the Image.

	\return
		Point object that holds the rendering offsets for the requested Image.

	\exception UnknownObjectException	thrown if no Image named \a name is defined for the Imageset
	*/
	Point	getImageOffset(const String& name) const		{return getImage(name).getOffsets();}


	/*!
	\brief
		return the x rendering offset for the named image.

	\param name
		String object holding the name of the Image.

	\return
		float value equal to the x rendering offset applied when drawing the requested Image.

	\exception UnknownObjectException	thrown if no Image named \a name is defined for the Imageset
	*/
	float	getImageOffsetX(const String& name) const		{return getImage(name).getOffsetX();}


	/*!
	\brief
		return the y rendering offset for the named image.

	\param name
		String object holding the name of the Image.

	\return
		float value equal to the y rendering offset applied when drawing the requested Image.

	\exception UnknownObjectException	thrown if no Image named \a name is defined for the Imageset
	*/
	float	getImageOffsetY(const String& name) const		{return getImage(name).getOffsetY();}

	
	/*!
	\brief
		Define a new Image for this Imageset

	\param name
		String object holding the name that will be assigned to the new Image, which must be unique within the Imageset.

	\param position
		Point object describing the pixel location of the Image on the image file / texture associated with this Imageset.

	\param size
		Size object describing the dimensions of the Image, in pixels.

	\param render_offset
		Point object describing the offsets, in pixels, that are to be applied to the Image when it is drawn.

	\return
		Nothing

	\exception AlreadyExistsException	thrown if an Image named \a name is already defined for this Imageset
	*/
	void	defineImage(const String& name, const Point& position, const Size& size, const Point& render_offset)
	{
		defineImage(name, Rect(position.d_x, position.d_y, position.d_x + size.d_width, position.d_y + size.d_height), render_offset);
	}


	/*!
	\brief
		Define a new Image for this Imageset

	\param name
		String object holding the name that will be assigned to the new Image, which must be unique within the Imageset.

	\param image_rect
		Rect object describing the area on the image file / texture associated with this Imageset that will be used for the Image.

	\param render_offset
		Point object describing the offsets, in pixels, that are to be applied to the Image when it is drawn.

	\return
		Nothing

	\exception AlreadyExistsException	thrown if an Image named \a name is already defined for this Imageset
	*/
	void	defineImage(const String& name, const Rect& image_rect, const Point& render_offset);


	/*!
	\brief
		Queues an area of the associated Texture the be drawn on the screen.  Low-level routine to be used carefully!

	\param source_rect
		Rect object describing the area of the image file / texture that is to be queued for drawing

	\param dest_rect
		Rect describing the area of the screen that will be filled with the imagery from \a source_rect.

	\param z
		float value specifying 'z' order.  0 is topmost with increasing values moving back into the screen.

	\param clip_rect
		Rect object describing a 'clipping rectangle' that will be applied when drawing the requested imagery

	\param colours
		ColourRect object holding the ARGB colours to be applied to the four corners of the rendered imagery.

	\return
		Nothing
	*/
	void	draw(const Rect& source_rect, const Rect& dest_rect, float z, const Rect& clip_rect,const ColourRect& colours) const;


	/*!
	\brief
		Queues an area of the associated Texture the be drawn on the screen.  Low-level routine to be used carefully!

	\param source_rect
		Rect object describing the area of the image file / texture that is to be queued for drawing

	\param dest_rect
		Rect describing the area of the screen that will be filled with the imagery from \a source_rect.

	\param z
		float value specifying 'z' order.  0 is topmost with increasing values moving back into the screen.

	\param clip_rect
		Rect object describing a 'clipping rectangle' that will be applied when drawing the requested imagery

	\param top_left_colour
		ARGB colour to be applied to the top left corner of the rendered imagery.

	\param top_right_colour
		ARGB colour to be applied to the top right corner of the rendered imagery.

	\param bottom_left_colour
		ARGB colour to be applied to the bottom left corner of the rendered imagery.

	\param bottom_right_colour
		ARGB colour to be applied to the bottom right corner of the rendered imagery.

	\return
		Nothing
	*/
	void	draw(const Rect& source_rect, const Rect& dest_rect, float z, const Rect& clip_rect, colour top_left_colour = -1, colour top_right_colour = -1,  colour bottom_left_colour = -1, colour bottom_right_colour = -1) const
	{
		draw(source_rect, dest_rect, z, clip_rect, ColourRect(top_left_colour, top_right_colour, bottom_left_colour, bottom_right_colour));
	}


	/*!
	\brief
		Return whether this Imageset is auto-scaled.

	\return
		true if Imageset is auto-scaled, false if not.
	*/
	bool	isAutoScaled(void) const		{return d_autoScale;}


	/*!
	\brief
		Return the native display size for this Imageset.  This is only relevant if the Imageset is being auto-scaled.

	\return
		Size object describing the native display size for this Imageset.
	*/
	Size	getNativeResolution(void) const	{return Size(d_nativeHorzRes, d_nativeVertRes);}


	/*!
	\brief
		Enable or disable auto-scaling for this Imageset.

	\param setting
		true to enable auto-scaling, false to disable auto-scaling.

	\return
		Nothing.
	*/
	void	setAutoScalingEnabled(bool setting);


	/*!
	\brief
		Set the native resolution for this Imageset

	\param size
		Size object describing the new native screen resolution for this Imageset.

	\return
		Nothing
	*/
	void	setNativeResolution(const Size& size);


	/*!
	\brief
		Notify the Imageset of the current (usually new) display resolution.

	\param size
		Size object describing the display resolution

	\return
		Nothing
	*/
	void	notifyScreenResolution(const Size& size);


protected:
	/*************************************************************************
		Implementation Constants
	*************************************************************************/
	static const char	ImagesetSchemaName[];			//!< Filename of the XML schema used for validating Imageset files.


	/*************************************************************************
		Implementation Functions
	*************************************************************************/
	/*!
	\brief
		Initialise the Imageset with information taken from the specified file.

	\param filename
		String object that holds the name of the Imageset data file that is to be processed.

	\return
		Nothing

	\exception	FileIOException		thrown if something goes wrong while processing the file \a filename.
	*/	
	void	load(const String& filename);


	/*!
	\brief
		Unloads all loaded data and leaves the Imageset in a clean (but un-usable) state.  This should be called for cleanup purposes only.
	*/
	void	unload(void);


	/*!
	\brief
		set the Texture object to be used by this Imageset.  Changing textures on an Imageset that is in use is not a good idea!

	\param texture
		Texture object to be used by the Imageset.  The old texture is NOT disposed of, that is the clients responsibility.

	\return
		Nothing

	\exception	NullObjectException		thrown if \a texture is NULL
	*/
	void	setTexture(Texture* texture);


	/*!
	\brief
		Sets the scaling factor for all Images that are a part of this Imageset.

	\return
		Nothing.
	*/
	void	updateImageScalingFactors(void);

	/*************************************************************************
		Implementation Data
	*************************************************************************/
	typedef	std::map<String, Image>	ImageRegistry;
	String			d_name;						//!< Holds the name of this imageset.
	ImageRegistry	d_images;					//!< Registry of Image objects for the images defined for this Imageset
	Texture*		d_texture;					//!< Texture object that handles imagery for this Imageset

	// auto-scaling fields
	bool	d_autoScale;			//!< true when auto-scaling is enabled.
	float	d_horzScaling;			//!< current horizontal scaling factor.
	float	d_vertScaling;			//!< current vertical scaling factor.
	float	d_nativeHorzRes;		//!< native horizontal resolution for this Imageset.
	float	d_nativeVertRes;		//!< native vertical resolution for this Imageset.
};

} // End of  CEGUI namespace section

#endif	// end of guard _CEGUIImageset_h_
