#include "TGraph.h"
#include "TCanvas.h"
#include "TAttFill.h"
#include "TLine.h"
#include "TColor.h"



void em()
{

   	TCanvas *c1 = new TCanvas ("c1","Graph",200,10,600,600);

   	c1->cd();
	
	TGraph *g1= new TGraph ("/home/isadora/Documents/root-framework/estrutura/tensaol.dat", "%lg %lg %*lg %*lg %*lg %*lg");

	//TGraph *g2= new TGraph ("/home/isadora/Documents/root-framework/estrutura/tensaol.dat", "%*lg %*lg %lg %lg %*lg %*lg");

	gPad->SetTickx();
	gPad->SetTicky();

	g1->SetTitle();
	g1->GetYaxis()->SetTitle("2V_{a} (V)");
	g1->GetXaxis()-> SetTitle("(RB)^{2}");
	g1->GetXaxis()->CenterTitle(1);
   	g1->GetYaxis()->CenterTitle(1);
	g1->GetXaxis()->SetLabelSize(0.030);
   	g1->GetYaxis()->SetLabelSize(0.03);
	g1->GetYaxis()-> SetNdivisions(10);
	g1->GetXaxis()-> SetNdivisions(10);
	g1->GetXaxis()->SetTickSize(0.03);
   	g1->GetYaxis()->SetTickSize(0.03);
   
	g1->GetXaxis()->SetRangeUser(1.5,4.0);
	g1->GetYaxis()-> SetRangeUser(300,690);
	//g2->GetXaxis()->SetRangeUser(1.5,4.0);
	//g2->GetYaxis()-> SetRangeUser(300,690);

   	g1->SetMarkerStyle(22);
   	//g1->SetLineColor(kMagenta+2);
   	g1->SetMarkerColor(kRed);
   	g1->SetMarkerSize(1.5);

   	//g2->SetMarkerStyle(22);
   	////g2->SetMarkerColor(kBlue);
   	//g2->SetMarkerSize(1.5);

   	TF1 *f1 = new TF1("f1", "([1]*x)",0,1.5);
	f1->SetParameters(1);
	f1->SetLineWidth(2);
	f1->SetLineColor(kOrange);
	g1->Fit("f1");
	f1->Draw("same");

	//TF1 *f2 = new TF1("f2", "([2]*x)",0,1.5);
	//f2->SetParameters(2);
	//f2->SetLineWidth(2);
	//f2->SetLineColor(kMagenta);
	//g2->Fit("f2");
	//f2->Draw("same");

   auto legend = new TLegend(0.3,0.3,0.62,0.63);
   legend->SetBorderSize(0);
   legend->SetTextSize(0.030);
   legend->AddEntry(g1,"Calculado para 2V_{a}=340","p");
   //legend->AddEntry(g2,"Calculado para 2V_{a}=380","p");
   legend->AddEntry("f1","Fit (#frac{e}{m}(RB)^{2})","l");
   //legend->AddEntry("f2","Fit (#frac{e}{m}(RB)^{2})","l");
   

	g1->Draw("AP");
	//g2->Draw("same");
	legend->Draw();
	c1->Update();

} 