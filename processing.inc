<?php




class processor{
    
    function __construct($filename){
        $this->file = $filename;
    }
    
    function csvextract(){
        $setnames=$fields=array();
        $row=0;
        
        if(($line=fopen($this->file,"r"))!==FALSE){
            
            while(($data=fgetcsv($line))!==FALSE){
                //Sets field names as associative array names
                if(empty($fields)){
                    $fields=$data;
                    $setnames=$data;
                    continue;
                }
                //populates array with data
                foreach($data as $key=>$value){
                    $dataArray[$row][]=$value;
                }
                $row++;
            }
            
            $this->fieldnames = $fields;
            $this->dataset = $dataArray;
        }else{
            echo "could not open file.";
        }
    }
    
    
}
