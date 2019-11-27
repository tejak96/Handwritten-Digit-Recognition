The datasets are pretty minimalistic ascii data comprising of (32x32) spaces and '#'s representing a number pattern.

             ####               
           ########             
        ############            
      ###############           
      ###############           
      ###############           
       #######   #####          
       #####     #####          
       ##       ######          
               ######           
              #######           
             #######            
          ##########            
         ############           
       ################         
      ##################        
       ##################       
       ########   #######       
       #####       ######       
                    #####       
                     ######     
                     #####      
                     #####      
                    ######      
       ####        #######      
       #####     ########       
       ######  #########        
        #################       
        #################       
        ###############         
          ##########            
            ######              
            
The value of :
  OccuranceOf(Char-0_0 at 0_0) * OccuranceOf(Char-0_1 at 0_1) * ... * OccuranceOf(Char-1023_1023 at 1023_1023)
  is calculated, for each combination (0-9), and maximum output of this value is returned as predictedOutput.
  As the result is very very close to zero (about 10^-1024),
  log10 values are used instead, so they can be added to get a final result.

Training Data (1798 models) : Testing Data (943) ie, (65.6% : 34.4%) and closer distributions of data seems to achieve >80% accuracies.
Compared to (90% : 10%) or (50% : 50%) sets which achieved <80%. 

Same prediction algorithm can be used on square black and white images, although even greater amounts of data are required
to train those models.

Decision trees gives lower accuracies compared to Naive Bayes classifier, whereas ANN's impl in Python/R gave higher accuracies.
