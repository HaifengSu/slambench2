/*

 Copyright (c) 2017 University of Edinburgh, Imperial College, University of Manchester.
 Developed in the PAMELA project, EPSRC Programme Grant EP/K008730/1

 This code is licensed under the MIT License.

 */

#include "io/openni2/ONI2Frame.h"

using namespace slambench::io::openni2;

ONI2Frame::ONI2Frame(Sensor *sensor, const openni::VideoFrameRef& frameref) {
	FrameSensor = sensor;
	Timestamp.Ns = frameref.getTimestamp() % 1000000000;
	Timestamp.S = frameref.getTimestamp() / 1000000000;
	_data = malloc(frameref.getDataSize());
	memcpy(_data, frameref.getData(), frameref.getDataSize());
}

void* ONI2Frame::GetData() {
	return _data;
}

void ONI2Frame::FreeData() {
	free(_data);
	_data = nullptr;
}
