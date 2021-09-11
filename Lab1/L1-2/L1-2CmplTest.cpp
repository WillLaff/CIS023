#include <iostream>
#include <string>
#include "patientType.h"
#include "billType.h"

using namespace std;

int main()
{
    patientType newPatient;
    newPatient.setInfo();
    newPatient.setID("1234");
    
	string x = newPatient.getID();
    
	int a;
	newPatient.setBirthDate();
	a=newPatient.getBirthDay();
    a=newPatient.getBirthMonth();
    a=newPatient.getBirthYear();

    newPatient.setDoctorName();
    newPatient.setDoctorSpl();
    x=newPatient.getDoctorFName();
    x=newPatient.getDoctorLName();

    x=newPatient.getDoctorSpl();

    newPatient.setAdmDate();
    a=newPatient.getAdmDay();
    a=newPatient.getAdmMonth();
    a=newPatient.getAdmYear();

    newPatient.setDisDate();
    a=newPatient.getDisDay();
    a=newPatient.getDisMonth();
    a=newPatient.getDisYear();

    patientType y();

	billType newBill;
    newBill.setInfo();

    newBill.setID("1234");
    x=newBill.getID();

    newBill.setPharmacyCharges();
    double b=newBill.getPharmacyCharges();
    newBill.updatePharmacyCharges();

    newBill.setRoomRent();
    b=newBill.getRoomRent();
    newBill.updateRoomRent();

    newBill.setDoctorFee();
    b=newBill.getDoctorFee();
    newBill.updateDoctorFee();

    b= newBill.billingAmount();

	system("pause");
    
    return 0;
}
