#include "Banco.h"



Banco::Banco()
{
}


Banco::~Banco()
{
}

void Banco::realizar_transferencia_num_cuenta(Transferencia transferencia)
{
	if (transferencia.cuenta_origen.numero_cuenta.validar() && transferencia.cuenta_destino.numero_cuenta.validar())
	{
		for (auto &cuenta : cuentas)
		{
			if (cuenta.numero_cuenta.numero_cuenta_completo == transferencia.cuenta_origen.numero_cuenta.numero_cuenta_completo)
			{
				if (cuenta.balance + cuenta.limite_operacion >= transferencia.cantidad)
					cuenta.balance -= transferencia.cantidad;
				break;
			}
		}
		for (auto &cuenta : cuentas)
		{
			if (cuenta.numero_cuenta.numero_cuenta_completo == transferencia.cuenta_destino.numero_cuenta.numero_cuenta_completo)
			{
				if (cuenta.balance + cuenta.limite_operacion >= transferencia.cantidad)
					cuenta.balance += transferencia.cantidad;
				break;
			}
		}
	}
}

void Banco::realizar_transferencias_num_cuenta()
{	
	for (auto transferencia : transferencias)
	{
		for (auto &cuenta_origen : cuentas)
		{
			if (cuenta_origen.numero_cuenta.numero_cuenta_completo == transferencia.cuenta_origen.numero_cuenta.numero_cuenta_completo)
			{
				if (cuenta_origen.balance -transferencia.cantidad>= -cuenta_origen.limite_operacion) {

					for (auto &cuenta : cuentas)
					{
						if (cuenta.numero_cuenta.numero_cuenta_completo == transferencia.cuenta_destino.numero_cuenta.numero_cuenta_completo)
						{
							cuenta_origen.balance -= transferencia.cantidad;
							cuenta.balance += transferencia.cantidad;
							break;
						}
					}
				}
				break;
			}
		}
	}
}


void Banco::realizar_transferencia_persona(Transferencia transferencia)
{
	for (auto &cuenta : cuentas)
	{
		if (cuenta.nombre == transferencia.persona_origen)
		{
			cuenta.balance -= transferencia.cantidad;
			break;
		}
	}
	for (auto &cuenta : cuentas)
	{
		if (cuenta.nombre == transferencia.persona_destino)
		{
			cuenta.balance += transferencia.cantidad;
			break;
		}
	}
}
