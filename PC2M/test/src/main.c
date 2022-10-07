#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "csv_manager.h"
#include "album_driver.h"
#include "album_filter.h"

int main( void)
{
	album_t *album = loadFile("/home/mtar/Documents/skola/s2/PC2M/C10/output/zadani10_databaze.csv");

	printfAllAlbums(album);
	album = sortAlbums(album, albumScore, 1);
	printfAllAlbums(album);
	// printfAlbum(getAlbum(album, "The Violin Player"));
	saveAlbumsList(album, "/home/mtar/Documents/skola/s2/PC2M/C10/output/zadani10_databaze_save.csv");

	album_compare_prototype_t *x = (album_compare_prototype_t *)malloc(sizeof(album_compare_prototype_t));;
	strcpy(x->name, "\0");
	strcpy(x->interpreter, "AC-DC");
	x->year = 2000;
	strcpy(x->genre, "\0");
	x->score = -1;

	album_list_t *list = getAlbumSortedList(album, x);
	printAlbumList(list);
	saveFilteredAlbumList(list, "/home/mtar/Documents/skola/s2/PC2M/C10/output/filtered_databaze_save.csv");
  	return 0;
}