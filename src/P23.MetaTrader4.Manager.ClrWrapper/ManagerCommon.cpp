#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

Common^ P23::MetaTrader4::Manager::ClrWrapper::ManagerCommon()
{
	ConCommon configuration;
	int result = _manager->Manager->CfgRequestCommon(&configuration);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}
	return Convert(&configuration);
}