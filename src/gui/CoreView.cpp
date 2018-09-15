/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "CoreView.h"

namespace kImageAnnotator {

CoreView::CoreView()
{
	mAnnotationArea = new AnnotationArea();
	mAnnotationView = new AnnotationView(mAnnotationArea);
	addWidget(mAnnotationView);

	connect(mAnnotationArea, &AnnotationArea::imageChanged, this, &CoreView::imageChanged);
}

CoreView::~CoreView()
{
	delete mAnnotationArea;
	delete mAnnotationView;
}

QImage CoreView::image() const
{
	return mAnnotationArea->image();
}

void CoreView::loadImage(const QPixmap &pixmap)
{
	mAnnotationArea->loadImage(pixmap);
}

void CoreView::showAnnotator()
{

}

void CoreView::showCropper()
{

}

void CoreView::showScaler()
{

}

QAction *CoreView::undoAction()
{
	return mAnnotationArea->undoAction();
}

QAction *CoreView::redoAction()
{
	return mAnnotationArea->redoAction();
}

QSize CoreView::sizeHint() const
{
	return mAnnotationView->sizeHint();
}

} // namespace kImageAnnotator