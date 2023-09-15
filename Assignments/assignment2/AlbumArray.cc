#include "AlbumArray.h"

//constructor which initializes the albumpointers and numAlbums 
AlbumArray::AlbumArray() {
    albumPointers = new Album*[MAX_ARRAY];
    numAlbums = 0;
}

//destructor that frees memory
AlbumArray::~AlbumArray(){
    delete[] albumPointers;
}

//check if number of albums is equal the size of max array return true otherwise
bool AlbumArray::isFull(){
    if(numAlbums == MAX_ARRAY){
        return true;
    }
    return false;
    
}

//this function adds an album to the array if it is not already full
//uses insertion sort to add the new album in right order
bool AlbumArray::add(Album* album) {
    if (isFull()) {
        return false;
    }

    //initialize index to numAlbums
    int index = numAlbums;
    //so while the index is greater than 0 and the new album is less than previous album in the array, shift the previous album to right
    while (index > 0 && album->lessThan(*albumPointers[index-1])) {
        albumPointers[index] = albumPointers[index-1];
        index--;
    }
    //add the new album to its right place  and increament numAlbums in the array
    albumPointers[index] = album;
    numAlbums++;

    return true;
}
//retrieves an album with that title from the array and returns null otherwise
Album* AlbumArray::get(const string& title) {
    for (int i = 0; i < numAlbums; i++) {
        if (albumPointers[i]->getTitle() == title) {
            return albumPointers[i];
        }
    }
    return nullptr;
}


//retrieves album from the specific index otherwise returns null
Album* AlbumArray::get(int index){
    if (index >= 0 && index < numAlbums) {
        return albumPointers[index];
    } else {
        return nullptr;
    }
}

//this function removes the album given the title of the album
Album* AlbumArray::remove(const string& title) {
    for (int i = 0; i < numAlbums; i++) {
        if (albumPointers[i]->getTitle() == title) {
            Album* removed_album = albumPointers[i];
            //move the albums to the right of the removed removed album to the left by 1
            for (int j = i; j < numAlbums-1; j++) {
                albumPointers[j] = albumPointers[j+1];
            }
            //decreament the number of albums in the array and return the removed_albums
            numAlbums--;
            return removed_album;

            //again this function is works like add but operation is vice versa.
        }
    }
    return nullptr;
}

//removes the album given the specific index.
Album* AlbumArray::remove(int index) {
    //if index is larger than size of array or less than 0 we return null
    if (index < 0 || index >= numAlbums) {
        return nullptr;
    }
    Album* removed_album = albumPointers[index];

    for (int i = index; i < numAlbums-1; i++) {
        //shift the albums to the right by 1
        albumPointers[i] = albumPointers[i+1];
    }
    //decreament number of albums
    numAlbums--;
    //return removed_album
    return removed_album;
}

//return the size of the array or numAlbums
int AlbumArray::size() const {
    return numAlbums;
};

//display in the console
void AlbumArray::print() const {
    for (int i = 0; i < numAlbums; i++) {
        albumPointers[i]->print();
        cout << endl;
    }
}



