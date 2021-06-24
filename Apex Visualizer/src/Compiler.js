import React ,{useEffect, useState} from 'react';
import { TextareaAutosize } from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableContainer from '@material-ui/core/TableContainer';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';
import './compiler.css'

const fs = require('fs')

const useStyles = makeStyles({
    outer:{
        width: 100,
        backgroundColor: "black",
        color:"white",
    },
    table: {
      maxWidth: 100,
    },
  });

  
function Compiler(){

    const [text , setText] = useState({
        code : [],
        vm : {},
        label : {},
        line : Number(0) ,
        varupdate : "-1"
    });
    const[start , setStart] = useState(true);

    const [ line , setLine] = useState(-1);

    const classes = useStyles();


    function rtrim(x, characters) {
        var start = 0;
        var end = x.length - 1;
        while (characters.indexOf(x[end]) >= 0) {
          end -= 1;
        }
        return x.substr(0, end + 1);
      }

    const showFile = async (e) => {
        e.preventDefault()
        //console.log(e.target.value);
        let vm = {};
        let labels ={};
        let curtext = e.target.value;  
        let newText = curtext.split ('\n').map ((item, i) => item);
        //console.log(newText);
        for(let i = 0 ; i< newText.length ;i++){
            newText[i] = rtrim(newText[i] , ' ');
            let tokens = newText[i].split(' ').map ((item, i) => item);
            if(tokens.length!=1 && tokens[0]!='goto' && tokens[0]!='if' && tokens[0]!= "If"){
                vm[tokens[0]]  = "-";
            }
            if(tokens.length==1){
                labels[tokens[0]] = i;
            }
          //  console.log(tokens);
            newText[i] = tokens;
        }
        //console.log(newText);
        setText({
            code : newText ,
            vm : vm,
            label : labels,
            line : -1 ,
            varupdate : "-1"
        })
     
    }
    // console.log("code" ,text["code"]);
    // console.log("vm " ,text["vm"]);
    // console.log("label",text["label"]);

    function nextState(){
        console.log(text["line"]);
        let lineNo = Number (text["line"]);
        lineNo++;

        if(lineNo>= text["code"].length){
            alert("Code completed");

            return;
        }
       // console.log(lineNo);

        let first = text["code"][lineNo][0];
        let code = text["code"];
      //  console.log("cur line : ",code[lineNo]);
        if(code[lineNo][1]=='='){
            if(code[lineNo].length>=5){
                
                let arg1 =  code[lineNo][2] ;
                let arg2 =  code[lineNo][4] ;

                 arg1 = ( arg1.charAt(0)>='0' && arg1.charAt(0)<='9' )? Number(arg1) :text["vm"][  arg1 ];
                let op = code[lineNo][3] ;
                 arg2 =  ( arg2.charAt(0)>='0' && arg2.charAt(0)<='9' )? Number(arg2) :text["vm"][  arg2];
                let temp = -1;

               // console.log("arg2 ",arg2);

                if(op == '+'){
                    temp  = arg1 + arg2;
                }else if(op == '-'){
                    temp  = arg1 - arg2;
                }else if(op == '*'){
                    temp  = arg1 * arg2;
                }else if(op == '/'){
                    temp  = arg1 / arg2;
                }else if(op == '<'){
                    temp  = arg1 < arg2 ? 1 :0;
                }else if(op == '>'){
                    temp  = arg1 > arg2 ? 1 :0;
                }else if(op == '!='){
                    temp  = (arg1 != arg2) ? 1 :0;
                }else if(op == '>='){
                    temp  = arg1 >= arg2 ? 1 :0;
                }else if(op == '<='){
                    temp  = arg1 <= arg2 ? 1 :0;
                }else if(op == '=='){
                    temp  = arg1 == arg2 ? 1 :0;
                }
                let third = code[lineNo][2];
                    
                let new_obj = { ... text["vm"]};
                new_obj[first] = parseInt(temp);
                setText(text=>{
                    return{
                        ...text ,
                        "vm" : new_obj,
                        "line" : lineNo ,            
                        varupdate: first
                    }
                })
            }else if(code[lineNo].length==4){
                let arg1 =  text["vm"][code[lineNo][3]] ;

                 let temp = { ... text["vm"]};
                    temp[first] = parseInt(arg1) ==0 ? 1 :0;
                    setText(text=>{
                        return{
                            ...text ,
                            "vm" : temp,
                            "line" : lineNo ,            
                            varupdate: first
                        }
                    })
            }
            else{
                if(code[lineNo][2].charAt(0) >= '0' && code[lineNo][2].charAt(0) <= '9'){
                    let third = code[lineNo][2];
                    
                    let temp = { ... text["vm"]};
                    temp[first] = parseInt(third);
                    setText(text=>{
                        return{
                            ...text ,
                            "vm" : temp,
                            "line" : lineNo ,            
                            varupdate: first
                        }
                    })
                        
                }else{
                    let third =Number( text["vm"][code[lineNo][2] ]);
                    
                    let temp = { ... text["vm"]};
                    temp[first] = parseInt(third);
                    setText(text=>{
                        return{
                            ...text ,
                            "vm" : temp,
                            "line" : lineNo ,            
                            varupdate: first
                        }
                    })
                }
            } 
        }else{
            
            let res = lineNo ;
            if( first == "If"){
              //  alert("yaha aa gaya");
              let arg1 = text["vm"][ code[lineNo][1] ];
              let target_line = text["label"][ code[lineNo][3]  +":" ];
              res = (arg1 !=0) ? target_line  : lineNo;       

            }else if(first=="goto"){
                let target_line = text["label"][ code[lineNo][1]  +":" ];
                res = target_line  ;     
            }

            setText(text=>{
                return{
                    ...text,
                    "line" : res
                }
            })
        }
    }
      
    console.log("line no  :" , text["line"]);
    console.log("values no  :" , text["vm"]);
    console.log("values no  :" , text["label"]);

    
        return (<div>
            <h1 id="heading" className="neon">APEX VISUALIZER</h1>

            { start &&
            <div className="box">
                 <TextareaAutosize id="textbox" rows="20" cols="20" onChange={(e) => showFile(e)} placeholder="Enter your code here" spellCheck="false"/>
                 <br></br>
                <div className="run" ><button className="button btnPush btnRed " onClick={()=>{setStart(start=>{return !start})}}>Run</button></div>
                 
             </div>
                }
       
            <br></br>
         

             { !start &&   
            <div className="row">
                <div className="column1">
                    <table  id="code">
                        <thead>
                            <tr>
                                <th>Pointer</th>
                                <th>Code</th>
                            </tr>
                        </thead>
                        
                        
                        <tbody>
                            { text["code"].length>0 ? text["code"].map((row , index) => (
                                <tr>
                                    <td id="pointer">{ index==text["line"]?<i class="fas fa-long-arrow-alt-right"></i>:""} </td>
                                    <td> {row.join(" ")}</td>
                                </tr>
                            )) : null 
                            }
                        </tbody>
                    
                    </table>
                </div>
        
                    
                <div className="contain">
                    <button className="click button btnPush btnRed" onClick={()=>{setStart(start=>{return !start})}}  >New Input</button>
                    <button className="click button btnPush btnBlueGreen" onClick={nextState}  >Next</button>
                </div>

                <div className="column2">
                    <table id="symbol">
                        <thead>
                            <th>
                                Variable
                            </th>
                            <th>
                                Value
                            </th>
                        </thead>
                        
                        <tbody>
                        {Object.entries(text["vm"]).map(([key, value]) => (
                            <tr key={key}>
                                <td>{ text["varupdate"]==key?<i class="fas fa-long-arrow-alt-right" id="pointer"></i>:""}{"       "+key}</td>
                                <td>{value}</td>  
                            </tr>
                        ))}
                        
                        </tbody>
                    
                    </table>
                </div>
            </div>
        }
 

        <footer className="footer-distributed">

			<div className="footer-left">

				<h3>APEX<span>visualizer</span></h3>

				<p className="footer-links">
					<a href="#">github <a href="#"><i className="fa fa-github"></i></a></a>
				
				</p>

				<p className="footer-company-name">Advanced Programming Experience © 2021</p>

				<div className="footer-icons">

					<a href="#"><i className="fa fa-facebook"></i></a>
					<a href="#"><i className="fa fa-twitter"></i></a>
					<a href="#"><i className="fa fa-linkedin"></i></a>
					<a href="#"><i className="fa fa-github"></i></a>

				</div>

			</div>

			<div className="footer-right developer">

				<p>Developers :</p>
                <br/>
				<p>VISHESH JAIN <span className="roll">( 2K18/CO/391 )</span> </p><br/>
				<p>VIKAS YADAV <span className="roll">( 2K18/CO/386 )</span></p><br/>
				<p>VAIBHAV VARSHNEY <span className="roll">( 2K18/CO/382 )</span></p><br/>

				
			</div>

		</footer>

        </div>
        )


      }
export default Compiler;