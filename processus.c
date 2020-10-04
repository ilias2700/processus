#include<stdio.h>
#include<stdlib.h>
#define N 30

typedef struct processus
{
	int temps_arrivee,temps_exucution,temps_calcul,temps_entree_sortie,temps_fin_dexucution,priorite,temps_restant;
	
}processus;



	int main()
	{
		
		// ----- Les Variables -------
			int choix,quantum,quit,nmbr_prossessus,s,t,priorite,min,k=1,b=0,temp[N],wt[N],tat[N];
			int i,j,nb,sfin,ss,ssej,q,ttime,c; 
			processus* processeur;
			processus permut;
			int permutation;
			float tem=0 ,tam=0;
			int pid,* pri;
		
			
		
		
		
		
	      // Menu des Algorithme pour choisir l'un des 6 Algorithmes 
	      printf("\n ********************* MINI PROJET DE SYSTEME D'EXPLOITATION ************************\n\n");
	 
	 
	 do{
	 	
 
 
 
		      printf("\n___________ Version Non Preemptive________________________________________________\n");
		      
		      printf(" \n 1 - Pour FIFO ");
		      
		      printf(" \n 2 - Pour Priorite ");
		
		      printf(" \n 3 - Pour  Le Plus Court D'abord \n");
		      
		      printf("\n___________ Version Preemptive____________________________________________________\n");
		      
		      printf(" \n 4 - Pour Round-Robbin (preemptive de FIFO) ");
		
		      printf(" \n 5 - Pour Proprite preemptive  (Preemptive De Priorite) ");
		
		      printf(" \n 6 - Pour Temps Restants Plus Court D'abord (Preemptive De Plus Court D'abord)\n");
		      
		      printf("\n___________________________________________________________________________________\n\n");
		      
		      printf("\n ** SVP Choississiez Un Algorithme D'ordonnencement Parmi Les 6 Algorithmes **\n");
		
		
		      // Choix de l'algorithmes 
		      printf("\t");
		      scanf("%d",&choix);
		      
		      switch(choix){
		      	
		      	case 1 : 
				  {
		      		
		      		
		      	   printf ("\n***************  Vous Avez Choissi Algorithme De FIFO ***************\n");
			
		           printf ("\n Entrer Le Nombre De Processus\n");
		           printf(" ");
		           scanf("%d",&nmbr_prossessus);
		           
				   processeur=( processus *)malloc(sizeof( processus )*nmbr_prossessus);
		
		
		
		           for( i=0 ; i < nmbr_prossessus ; i++)
		           
		             {
		                    printf(" Entrer La Date D'arrivee Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_arrivee);
		                    printf(" Entrer la Duree De Calcul Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_calcul);
		                    printf(" Entrer la Duree D'Entree/Sortie Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_entree_sortie);
		             }
		
		
		

						
						/*Afficher l'ordonnancement appilqué*/
						 printf("\n___________________________________________________________________________________\n\n");
					   	printf("************* Ordonnancement De FIFO *****************\n");
					   	
					   	// Trier les Processus par Ordre Croissante selon le Temps d'arrivé 
					   	
					   	for(i=0;i<nmbr_prossessus+1;i++)
						
							for(j=i+1;j<nmbr_prossessus;j++)
							
							{
								if (processeur[i].temps_arrivee>processeur[j].temps_arrivee)
							
									{
										permut=processeur[i];
										processeur[i]=processeur[j];
										processeur[j]=permut;
									}
							
							}
							printf("\n");
						
						// Afficher la date d'arrivee et le temps d'execution de chaque processus
						
						printf("\nProcessus\t Temps D'arrive\t Temps De Calcul \tTemps D'Entree/Sortie \n\n");
						
						for (i=0;i<nmbr_prossessus;i++)
						{
							printf("p(%d)\t\t %dms \t\t %dms \t\t\t %dms\n",i+1,processeur[i].temps_arrivee,processeur[i].temps_calcul,processeur[i].temps_entree_sortie);
						}
							printf("\n");
							
						// Calcul la date De Sortie De Cheque Processus 
						
						
								
						
						
						
						
						printf("********* La Date De Sortie (Fin Exucution) Des %d processus **********\n\n",nmbr_prossessus);
							for(i=0;i<nmbr_prossessus;i++)
							{
								printf("\tp(%d)\t",i+1);
							
							}
							printf("\n");
							s = 0;
							for(i=0;i<nmbr_prossessus;i++)
							{
								s+=processeur[i].temps_calcul+processeur[i].temps_entree_sortie;
								printf("\t%dms\t",s);
							
							}
							
							printf("\n\n********** Le Taux D'occupation Du Processuer *********\n");
							t=0;
							for(i=0;i<nmbr_prossessus;i++)
							{
								t+=processeur[i].temps_calcul;
							}
						
							printf("\n\nLe Taux D'occupation Du processeur est = %d/%d",t,s);
							
						
							
								
							
									
							
							
							
							
							
							
							
						
							printf("\n___________________________________________________________________________________\n\n");
						
						break;
					}
				case 2 :
				  {
						printf ("\n***************  Vous Avez Choisi Algorithme De Priorite ***************\n");
			
				           printf ("   \n Entrer Le Nombre De Processus\n");
				           printf("\t");
				           scanf("%d",&nmbr_prossessus);
		           
				   		processeur=( processus *)malloc(sizeof( processus )*nmbr_prossessus);
		
		          	 for(i=0;i<nmbr_prossessus;i++)
		           
		             {
		                    printf(" Entrer La Date D'arrivee Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_arrivee);
		                    printf(" Entrer Le Temps De Calcul Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_calcul);
		                    printf(" Entrer La Priorite Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].priorite);
		             }
		             
		             for (i= 0 ; i<nmbr_prossessus ; i++)
		             {
		             	
		             	for(j=0 ; j<nmbr_prossessus ; j++)
						 {
		             		if(processeur[i].temps_arrivee < processeur[j].temps_arrivee)
		             		{
		             			permutation = processeur[j].temps_arrivee;
		             			processeur[j].temps_arrivee = processeur[i].temps_arrivee;
		             			processeur[i].temps_arrivee = permutation;
		             			
		             			permutation = processeur[j].temps_calcul;
		             			processeur[j].temps_calcul=processeur[i].temps_calcul;
		             			processeur[i].temps_calcul=permutation;
							 }
		             		
						 }
					 }
		                
		                for(j=0;i<nmbr_prossessus;j++)
		                {
		                	b=b+processeur[j].temps_calcul;
		                	min = processeur[k].temps_calcul;
		                	
		                	for(i=k;i<nmbr_prossessus;i++)
		                	{
		                		min=processeur[k].priorite;
		                		if(b>=processeur[i].temps_arrivee)
		                		{
		                			if(processeur[i].priorite<min)
		                			{
		                				permutation = processeur[k].temps_arrivee;
		                				processeur[k].temps_arrivee = processeur[i].temps_arrivee;
		                				processeur[i].temps_arrivee = permutation;
		                				
		                				permutation = processeur[k].temps_calcul;
		                				processeur[k].temps_calcul =processeur[i].temps_calcul;
		                				processeur[i].temps_calcul = permutation;
		                				
		                				permutation = processeur[k].priorite;
		                				processeur[k].priorite = processeur[i].priorite;
		                				processeur[i].priorite = permutation;
		                				
		                				
									}
								}
							}
							
							k++;
						}
						temp[0]=0;
						printf("\n___________________________________________________________________________________\n\n");
					    	printf("************* Ordonnancement De Priorite *****************\n");
						
						printf("\n\n Processus\t Temps D'arrive\t Temps De Calcul       Priorite\n ");
								for (i=0;i<nmbr_prossessus;i++)
								{
									wt[i]=0;
									tat[i]=0;
									temp[i+1] = temp[i] + processeur[k].temps_calcul;
									wt[i] = temp[i] - processeur[k].temps_arrivee;
									tat[i] = wt[i] + processeur[k].temps_calcul;
									tam = tam +wt[i];
									tem = tem +tat[i];
									printf("\n  p(%d)\t\t    %dms\t\t    %dms\t\t\t %d",i+1,processeur[i].temps_arrivee,processeur[i].temps_calcul,processeur[i].priorite);
								
								}
								
								printf("\n\n Temps Attende Moyen = %.2f",tam/nmbr_prossessus);
								printf("\n\n Temps exucution Moyen = %.2f",tem/nmbr_prossessus);

						
						printf("\n___________________________________________________________________________________\n\n");
						
						
						
						
		                
		                
		             
		             
		             
		             
		             
		             
		             /*
		             printf("\n\n Entrer La Priorite La Plus Important");
		             printf("\n 1 - Min ");
		             printf("\n 2 - Max ");
		             printf("\n\t");
		             scanf("%d",&priorite);
		             
		             
		             // Trier par priorité
		           switch(priorite)
		            {
		             	
		             	case 1 :
		             		{
		             			
		             			for(i=0;i<nmbr_prossessus+1;i++)
						
							for(j=i+1;j<nmbr_prossessus;j++)
							
							{
								if (processeur[i].priorite>processeur[j].priorite)
							
									{
										permut=processeur[i];
										processeur[i]=processeur[j];
										processeur[j]=permut;
									}
							
							}
							printf("\n");
		             			
		             			break;
							 }
					    case 2 : 
					    {
					    	
					    	for(i=1;i<nmbr_prossessus+1;i++)
						
							for(j=i+1;j<nmbr_prossessus;j++)
							
							{
								if (processeur[i].priorite<processeur[j].priorite)
							
									{
										permut=processeur[i];
										processeur[i]=processeur[j];
										processeur[j]=permut;
									}
							
							}
							printf("\n");
						}
							 
							 
					 }
		             
		             
		             		
						    
					    	
								printf("\n\n Processus\t Temps D'arrive\t Temps De Calcul       Priorite\n ");
								for (i=0;i<nmbr_prossessus;i++)
								{
								printf("\n  p(%d)\t\t    %dms\t\t    %dms\t\t\t %d",i+1,processeur[i].temps_arrivee,processeur[i].temps_calcul,processeur[i].priorite);
								}
		             
		             */
		             
		             
		             
		             
		             
						break;
					}
					
				case 3 : 
			      {
							printf ("\n***************  Vous Avez Choisi Algorithme De Plus Court D'abord ***************\n");
			
				           printf ("   \n Entrer Le Nombre De Processus\n");
				           printf("\t");
				           scanf("%d",&nmbr_prossessus);
		           
				   		processeur=( processus *)malloc(sizeof( processus )*nmbr_prossessus);
		
		          	 for(i=0;i<nmbr_prossessus;i++)
		           
		             {
		                    printf(" Entrer La Date D'arrivee Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_arrivee);
		                    printf(" Entrer Le Temps De Calcul Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_calcul);
		                    
		             }
		             
						             
						             printf("\n___________________________________________________________________________________\n\n");
					    	    	printf("************* Ordonnancement De Plus Court D'abord *****************\n");
									printf("\n\n Processus\t Temps D'arrive\t\t Temps De Calcul\n ");
									for (i=0;i<nmbr_prossessus;i++)
									{
									printf("\n  p(%d)\t\t      %dms\t\t\t%dms",i+1,processeur[i].temps_arrivee,processeur[i].temps_calcul);
									}
		             
		             
		             
		             
		             
		             printf("\n___________________________________________________________________________________\n\n");
		             
						break;
				
					}
					
				case 4 :
					{
						   printf ("\n***************  Vous Avez Choisi Algorithme De Round-Robbin ***************\n");
			
				           printf ("   \n Entrer Le Nombre De Processus\n");
				           printf("\t");
				           scanf("%d",&nmbr_prossessus);
				           
				           printf ("   \n Entrer Le Quantum\n");
				           printf("\t");
				           scanf("%d",&quantum);
		           
				   		processeur=( processus *)malloc(sizeof( processus )*nmbr_prossessus);
		
		          	 for(i=0;i<nmbr_prossessus;i++)
		           
		             {
		                    printf(" \nEntrer La Date D'arrivee Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_arrivee);
		                    printf(" \nEntrer Le Temps De Calcul Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_calcul);
		                    
		             }
		             
						             
						 printf("\n___________________________________________________________________________________\n\n");
						 
			    	     printf("************* Ordonnancement De Round-Robbin *****************\n");
					    	    	
					    // Trier les Processus par Ordre Croissante selon le Temps d'arrivé 
					   	
					   	for(i=0;i<nmbr_prossessus+1;i++)
						
							for(j=i+1;j<nmbr_prossessus;j++)
							
							{
								if (processeur[i].temps_arrivee>processeur[j].temps_arrivee)
							
									{
										permut=processeur[i];
										processeur[i]=processeur[j];
										processeur[j]=permut;
									}
							
							}
							printf("\n");
					    	    	
					    // Afficher les temps d'arrivé et De calcul
					    
									printf("\n\n Processus\t Temps D'arrive\t\t Temps De Calcul\n ");
									for (i=0;i<nmbr_prossessus;i++)
									{
									printf("\n  p(%d)\t\t      %dms\t\t\t%dms",i+1,processeur[i].temps_arrivee,processeur[i].temps_calcul);
									}
									
							// 
		             
		             
		             
		   						 printf("\n___________________________________________________________________________________\n\n");
						break;
					}
				case 5 :
					{
						 printf ("\n***************  Vous Avez Choisi Algorithme De Proprite preemptive ***************\n");
			
				           printf ("   \n Entrer Le Nombre De Processus\n");
				           printf("\t");
				           scanf("%d",&nmbr_prossessus);
		           
				   		processeur=( processus *)malloc(sizeof( processus )*nmbr_prossessus);
		
		          	 for(i=0;i<nmbr_prossessus;i++)
		           
		             {
		                    printf(" Entrer La Date D'arrivee Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_arrivee);
		                    printf(" Entrer Le Temps De Calcul Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_calcul);
		                    printf(" Entrer La Priorite Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].priorite);
		             }
		             
						             printf("\n___________________________________________________________________________________\n\n");
					    	    	printf("************* Ordonnancement De Proprite preemptive *****************\n");
						             
									printf("\n\n Processus\t Temps D'arrive\t Temps De Calcul       Priorite\n ");
									for (i=0;i<nmbr_prossessus;i++)
									{
									printf("\n  p(%d)\t\t    %dms\t\t    %dms\t\t\t %d",i+1,processeur[i].temps_arrivee,processeur[i].temps_calcul,processeur[i].priorite);
									}
		             
		             
		             
		             
		             
		             
		                     printf("\n___________________________________________________________________________________\n\n");
						break;
					}
					
				case 6 :
					{
						
							printf ("\n***************  Vous Avez Choisi Algorithme De Temps Restants Plus Court D'abord ***************\n");
			
				           printf ("   \n Entrer Le Nombre De Processus\n");
				           printf("\t");
				           scanf("%d",&nmbr_prossessus);
		           
				   		processeur=( processus *)malloc(sizeof( processus )*nmbr_prossessus);
		
		          	 for(i=0;i<nmbr_prossessus;i++)
		           
		             {
		                    printf(" Entrer La Date D'arrivee Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_arrivee);
		                    printf(" Entrer Le Temps De Calcul Du Processus (%d)\n",i+1);
		                    printf("\t");
		                    scanf("%d",&processeur[i].temps_calcul);
		                    
		             }
		             
						             
						        printf("\n___________________________________________________________________________________\n\n");
					    	    	printf("************* Ordonnancement De Temps Restants Plus Court D'abord *****************\n");
									     
								printf("\n\n Processus\t Temps D'arrive\t\t Temps De Calcul\n ");
								for (i=0;i<nmbr_prossessus;i++)
								{
								printf("\n  p(%d)\t\t      %dms\t\t\t%dms",i+1,processeur[i].temps_arrivee,processeur[i].temps_calcul);
								}
		             
		             
		             
		             
		             
		             
		             printf("\n___________________________________________________________________________________\n\n");
						break;
							
						}
					
					
						      	
				  }//switch
				
		
		
		// Pour Quittez Le Progrramme ou Non 
		    printf(" \n\nVous Etes Sur de vouloir Quitter Le Programme\n");
		    printf("\n 1 - Non ");
		    printf("\n 2 - Oui \n");
		    
		    scanf("%d",&quit);
		    printf("\n\n************************ FIN DE PROGRAMME *****************************\n\n");
		    
		}while(quit==1);
		    



	return 0;
	
}