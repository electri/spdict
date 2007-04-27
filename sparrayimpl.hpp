/*
 * Copyright 2007 Stephen Liu
 * For license terms, see the file COPYING along with this library.
 */

#ifndef __sparrayimpl_hpp__
#define __sparrayimpl_hpp__

#include <stdio.h>

#include "spdictionary.hpp"

// sorted array
class SP_SortedArrayNode {
public:
	SP_SortedArrayNode( void * item = 0 );
	~SP_SortedArrayNode();

	void setItem( void * item );
	void * getItem() const;
	void * takeItem();

private:
	void * mItem;
};

class SP_SortedArrayIterator : public SP_DictIterator {
public:
	SP_SortedArrayIterator( SP_SortedArrayNode ** list, int count );
	virtual ~SP_SortedArrayIterator();

	virtual const void * getNext( int * level = 0 );

private:
	SP_SortedArrayNode ** mList;
	int mCount;
	int mIndex;
};

class SP_SortedArrayImpl : public SP_Dictionary {
public:
	SP_SortedArrayImpl( SP_DictHandler * handler );
	virtual ~SP_SortedArrayImpl();	

	virtual int insert( void * item );
	virtual const void * search( const void * key ) const;
	virtual void * remove( const void * key );
	virtual int getCount() const;
	virtual SP_DictIterator * getIterator() const;

private:

	// @return >= 0 : found, -1 : not found
	int binarySearch( const void * item, int * insertPoint = 0,
			int firstIndex = 0, int size = -1 ) const;

	SP_SortedArrayNode ** mList;
	int mMaxCount;
	int mCount;

	SP_DictHandler * mHandler;
};

#endif

