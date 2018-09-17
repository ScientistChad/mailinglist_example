<?php

class db{
    
    function __construct(){
        //Connecting to database
        $conn = new mysqli('localhost','root','');

        //Testing database connection
        if($conn->connect_error){
            die('Could not connect:'.mysql_error());
        }else{
            $qdb = 'CREATE DATABASE IF NOT EXISTS mailinglist';
            $conn->query($qdb);
            mysqli_select_db($conn,'mailinglist');
            
            //Check for tables and create if none found
            $qdbt = "CREATE TABLE IF NOT EXISTS users (
                    id int(10) AUTO_INCREMENT PRIMARY KEY, 
                    first_name varchar(50),
                    last_name varchar(50),
                    email varchar(100))";
            $res = $conn->query($qdbt);
            var_dump($res);
            
            echo "Connection to mailinglist successful.\r\n";
            $this->conn = $conn;
        }
    }
    
    
    function upload($data){
        foreach($data as $set){
            $sql = "INSERT INTO users (first_name, last_name, email) VALUES ('".$set[0]."','".$set[1]."','".$set[2]."')";
            $this->conn->query($sql);
        }
    }
    
    
    function close(){
        $this->conn->close();
    }
    
}



?>
