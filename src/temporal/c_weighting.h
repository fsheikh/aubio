/*
  Copyright (C) 2003-2009 Paul Brossier <piem@aubio.org>

  This file is part of aubio.

  aubio is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  aubio is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with aubio.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef _CDESIGN_H
#define _CDESIGN_H

/** \file

  Create a C-weighting filter
  
  This file creates a C-weighting digital filter, which reduces low and high
  frequencies and enhance the middle ones to reflect the ability of the human
  hearing.
  
  The implementation is based on the following standard:

    - IEC/CD 1672: Electroacoustics-Sound Level Meters, IEC, Geneva, Nov.  1996,
  for A- and C-weighting filters.
  
  See also:
  
    - <a href="http://en.wikipedia.org/wiki/A-weighting">A-Weighting on
  Wikipedia</a>
    - <a href="http://en.wikipedia.org/wiki/Weighting_filter">Weighting filter on
  Wikipedia</a>
    - <a href="http://www.mathworks.com/matlabcentral/fileexchange/69">Christophe
  Couvreur's 'octave' toolbox</a>
  
  The coefficients in this file have been computed using Christophe Couvreur's
  scripts in octave 3.0 (debian package 1:3.0.5-6+b2 with octave-signal
  1.0.9-1+b1 on i386), with <pre> [b, a] = cdsign(1/Fs) </pre> for various
  sampling frequencies (8000, 11025, 16000, 22050, 24000, 32000, 44100, 48000,
  88200, 96000, and 192000 Hz).

  The sampling frequency should normally be higher than 20kHz, but most common
  file sampling rates have been included for completeness.

*/

#ifdef __cplusplus
extern "C" {
#endif

/** create new C-design filter

  \param samplerate sampling frequency of the signal to filter. Should be one of 
  8000, 11025, 16000, 22050, 24000, 32000, 44100, 48000, 88200, 96000, and
  192000 Hz
  \param channels number of channels to allocate

  \return a new filter object

*/
aubio_filter_t * new_aubio_filter_c_weighting (uint_t samplerate, uint_t channels);

/** set feedback and feedforward coefficients of a C-weighting filter

  \param f filter object to get coefficients from

*/
void aubio_filter_set_c_weighting (aubio_filter_t *f);

#ifdef __cplusplus
}
#endif

#endif /* _CDESIGN_H */