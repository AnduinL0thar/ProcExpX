#include "FormatHelper.h"
#include <atltime.h>

CString FormatHelper::TimeSpanToString(int64_t ts) {
	auto str = CTimeSpan(ts / 10000000).Format(L"%D.%H:%M:%S");

	str.Format(L"%s.03d", str, (ts / 10000) % 1000);
	return str;
}

CStringA FormatHelper::FormatWithCommas(long long size) {
	CStringA result;
	result.Format("%lld", size);
	int i = 3;
	while (result.GetLength() - i > 0) {
		result = result.Left(result.GetLength() - i) + L"," + result.Right(i);
		i += 4;
	}
	return result;
}
