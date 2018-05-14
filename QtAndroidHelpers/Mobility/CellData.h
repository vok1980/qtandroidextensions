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

#pragma once

#include <boost/optional.hpp>
#include <QtCore/QSharedPointer>


namespace Mobility {

struct CellData
{
	void hashData(QByteArray & data) const;

	struct Data
	{
		Data(uint32_t cell_id);
		void hashData(QByteArray & data) const;

		// обязательный, int. Уникальный идентификатор соты. 32-битное положительное число.
		// Cell ID (CID) для GSM-сетей
		// Base Station ID (BID) для CDMA-сетей
		// UTRAN/GERAN Cell Identity (UC-Id) для WCDMA-сетей.
		uint32_t cell_id_;

		// необязательный, int.
		// Location Area Code (LAC) для GSM and WCDMA сетей.
		// Network ID (NID) для CDMA сетей. Число от 0 до 65535.
		boost::optional<uint16_t> location_area_code_;

		// необязательный, int. 0 <= MCC < 1000
		boost::optional<uint16_t> mobile_country_code_;

		// необязательный, int. 0 <= MNC < 1000
		boost::optional<uint16_t> mobile_network_code_;

		// необязательный, int. RSSI в dBm.
		boost::optional<int32_t> signal_strength_;

		// необязательный, int
		boost::optional<int32_t> timing_advance_;
	};

	typedef QList<Data> DataColl;
	DataColl data_;
	QString radio_type_;
};


typedef QSharedPointer<CellData> CellDataPtr;

}
