
**This is not a library for use in production, its purpose is entirely didactic!**

Works only with 24bpp and 32bpp bmp images and little endian machines

The test can be done with the following command:
```sh
make; make test; ./test
```

## Functions

|Function  | Description |
|--|--|
|[lbmp_load](/lbmp_load.c)| Load bmp from a file. It returns a void pointer that can be used with ***lbmp_set_pixel_color***, ***lbmp_get_pixel_color***, ***lbmp_get_width***, ***lbmp_get_height***, ***lbmp_get_size***, ***lbmp_save*** and ***lbmp_destroy***.|
| [lbmp_new](/lbmp_new.c) | Create a new bmp. It returns a void pointer that can be used with ***lbmp_set_pixel_color***, ***lbmp_get_pixel_color***, ***lbmp_get_width***, ***lbmp_get_height***, ***lbmp_get_size***, ***lbmp_save*** and ***lbmp_destroy***. |
|[lbmp_set_pixel_color](/lbmp_set_pixel_color.c)|Changes the pixel color in the image at the (***x,y***).|
|[lbmp_get_pixel_color](/lbmp_get_pixel_color.c)|Gets the pixel color in the image at the (***x,y***).|
|[lbmp_save.c](/lbmp_save.c")|Save to a file the image loaded with ***lbmp_load*** or created with ***lbmp_new***.|
|[lbmp_get_width](/lbmp_get_width.c)|Get image width.|
|[lbmp_get_height](/lbmp_get_height.c)|Get image height.|
|[lbmp_get_size](/lbmp_get_size.c)|Get image size.|
|[lbmp_strerror](/lbmp_strerror.c)|when a function returns an error the error code is placed in the variable **g_lbmperr**, this function gets the error message string.|
|[lbmp_destroy](/lbmp_destroy.c)|Free memory allocated by ***lbmp_load*** or ***lbmp_new***.|
