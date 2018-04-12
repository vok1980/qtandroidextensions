/*
	Offscreen Android Views library for Qt

	Authors:
		Vyacheslav O. Koscheev <vok1980@gmail.com>
		Ivan Avdeev marflon@gmail.com
		Sergey A. Galin sergey.galin@gmail.com

	Distrbuted under The BSD License

	Copyright (c) 2015, DoubleGIS, LLC.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	* Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.
	* Neither the name of the DoubleGIS, LLC nor the names of its contributors
	  may be used to endorse or promote products derived from this software
	  without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
	THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
	BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
	THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "CellData.h"


namespace Mobility {


CellData::Data::Data(uint32_t cell_id)
	: cell_id_(cell_id)
{
}


void CellData::Data::hashData(QByteArray & data) const
{
	data.append("CellData::Data");

	data.append("cell_id_");
	data.append(QByteArray::number(cell_id_));

	if (location_area_code_)
	{
		data.append("location_area_code_");
		data.append(QByteArray::number(*location_area_code_));
	}

	if (mobile_country_code_)
	{
		data.append("mobile_country_code_");
		data.append(QByteArray::number(*mobile_country_code_));
	}

	if (mobile_network_code_)
	{
		data.append("mobile_network_code_");
		data.append(QByteArray::number(*mobile_network_code_));
	}

	if (signal_strength_)
	{
		data.append("signal_strength_");
		data.append(QByteArray::number(*signal_strength_));
	}

	if (timing_advance_)
	{
		data.append("timing_advance_");
		data.append(QByteArray::number(*timing_advance_));
	}
}


void CellData::hashData(QByteArray & data) const
{
	data.append("CellData");
	data.append(QByteArray::number(data_.size()));
	data.append("#");
	data.append(radio_type_);
	data.append("#");

	for (const auto & item : data_)
	{
		item.hashData(data);
	}
}

} // namespace Mobility
