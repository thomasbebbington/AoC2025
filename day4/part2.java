import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class part2 {
	public static void main(String[] args){

		File f = new File("input.txt");
		Scanner reader;

		try{
			reader = new Scanner(f);
		} catch(FileNotFoundException e) {
			return;
		}
		
		char grid[][] = new char[140][140];

		for(int i = 0; i < 140; i++){
			String line = reader.nextLine();

			for(int j = 0; j < 140; j++){
				grid[i][j] = line.charAt(j);
			}
		}

		int removed;
		int totalremoved = 0;

		do{
			int newgrid[][] = new int[140][140];
			for(int i = 0; i < 140; i++){
				for(int j = 0; j < 140; j++){
					if(grid[i][j] == '@'){
						if(i-1>=0){
							newgrid[i-1][j]++;
							if(j-1>=0) newgrid[i-1][j-1]++;
							if(j+1<140) newgrid[i-1][j+1]++;
						}
						if(i+1<140){
							newgrid[i+1][j]++;
							if(j-1>=0) newgrid[i+1][j-1]++;
							if(j+1<140) newgrid[i+1][j+1]++;
						}
						if(j-1>=0) newgrid[i][j-1]++;
						if(j+1<140) newgrid[i][j+1]++;
					}
				}
			}
		
			removed = 0;
			for(int i = 0; i < 140; i++){
				for(int j = 0; j < 140; j++){
					if(newgrid[i][j] < 4 && grid[i][j] == '@') {
						grid[i][j] = '.';
						removed++;
					}
				}
			}		
			totalremoved += removed;	
		} while(removed != 0);

		System.out.println(totalremoved);
	}
}
